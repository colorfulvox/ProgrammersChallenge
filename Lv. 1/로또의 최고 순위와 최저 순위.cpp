/*

array에 각 등수를 저장한다.
(여기서 0 index가 1인 이유는 연산할때 zero의 갯수와 score의 갯수를 합한게 6이기
때문이다.)
=> array[6 - score - zero]

마지막 array에 6이 하나 더 저장된 이유도 조건에서 1개 or 0개 맞췄을때
6등으로 표시하기 때문이다.
=> array[6 - score]

*/
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
  vector<int> answer;

  vector<bool> table(46, false);
  int array[7] = {1, 2, 3, 4, 5, 6, 6};

  for (int i = 0; i < win_nums.size(); ++i) {
    table[win_nums[i]] = true;
  }

  int score = 0;
  int zero = 0;
  for (int i = 0; i < lottos.size(); ++i) {
    if (lottos[i] == 0)
      ++zero;
    else if (table[lottos[i]])
      ++score;
  }

  answer.push_back(array[6 - score - zero]);
  answer.push_back(array[6 - score]);

  return answer;
}