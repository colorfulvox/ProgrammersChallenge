/*
조건은 반드시 1개는 무조건 입는다.
face = 2, headgear = 2일때,
face : f1, f2
headgear : h1, h2
여기서 경우의 수는 4개 된다.

하지만, 안입는 경우의 수도 있다.
face기준 f1을 입는 경우, f2를 입는 경우, 둘다 안입는 경우
그래서 각 type별로 +1를 하고 곱해주면 된다.
answer = f(n) +1 * h(n) +1
하지만, 모두 안입는 경우는 없으니 마지막에 -1을 해준다.
answer--;
*/

#include <map>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
  int answer = 1;

  map<string, int> table;

  for (int i = 0; i < clothes.size(); ++i) {
    table[clothes[i][1]]++;
  }

  for (auto tm : table) {
    answer *= (tm.second + 1);
  }
  --answer;

  return answer;
}