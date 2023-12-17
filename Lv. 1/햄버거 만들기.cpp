/*
1. 1-2-3-1 레시피 배열과 현재 위치값을 나타내는 cur을 생성한다.
2. ingredient를 순회하면서 만약 레시피[cur]과 현재 ingredient값이 같으면
cur를 증가시켜 다음 검사를 진행한다.
3. 만약, 같지 않으면 cur을 0으로 초기화하고 현재 값과 다시 검사한다.
4. cur과 같던 다르던 table에 해당 값을 table의 마지막 위치에 저장한다.
5. 만약 cur == 4 즉, 1-2-3-1을 발견했을경우 table을 4번 pop_back하고
과거 데이터를 검사해야한다.
6. 1-2-3-1에서 1-2-[1-2-3-1]-3-1 과 같이 [1-2-3-1]을
pop_back하면 1-2가 남는데 최대로 1-2-3으로 남을 수도 있다.
7. 그래서 table의 이전 데이터에서 1을 먼저 찾은뒤 1을 찾을 경우 cur을 증가시키고
해당 위치(1의 위치)부터 1-2-3이 성립하는지 다시 검사한다.
8. 만약 1-2-3이 성립하지 않으면 cur을 0으로 초기화한다.
9. 7과 8번을 table.size()-3 즉, 3개의 위치값을 검사해야한다.
table.size()-1 : 1
table.size()-2 : 1-2
table.size()-3 : 1-2-3
가 되는지 검사하는것이다.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
  int answer = 0;
  vector<int> table;
  int recipe[4] = {1, 2, 3, 1};
  int cur = 0;

  for (auto in = ingredient.begin(); in < ingredient.end(); ++in) {
    if (recipe[cur] == *in)
      ++cur;
    else {
      cur = 0;
      if (recipe[cur] == *in) ++cur;
    }
    table.push_back(*in);

    if (cur == 4) {
      ++answer;
      cur = 0;
      for (int i = 0; i < 4; ++i) table.pop_back();
      if (table.size() > 0) {
        int size = table.size();
        for (int idx = size - 1; idx >= (size - 3); --idx) {
          if (idx < 0) break;
          if (table[idx] == 1) {
            cur++;
            for (int i = idx + 1; i < table.size(); ++i) {
              if (table[i] == recipe[cur])
                cur++;
              else {
                cur = 0;
                break;
              }
            }
          }
          if (cur > 0) break;
        }
      }
    }
  }

  return answer;
}