/*
h번 이상 h편이상 i <= max

[3, 0, 6, 1, 5]

0 : 1
1 : 1
2 : 0
3 : 1
4 : 0
5 : 1
6 : 1

max = 5

i = 0,
0번 이상 0편 이상 0 <= max(5) : O
=> answer = 0

i = 1, (max -= table[0])
1번 이상 1편 이상 1 <= max(4) : O
=> answer = 1

i = 2, (max -= table[1])
2번 이상 2편 이상 2 <= max(3) : O
=> answer = 2

i = 3,
3번 이상 3편 이상 3 <= max(3) : O
=> answer = 3

i = 4, (max -= table[3])
4번 이상 4편 이상 4 <= max(2) : X (조건이 안맞다.)
=> answer = X

[나머지 논문이 h번 이하 인용되었다면]
이 조건은 max -= table[i]를 하면서 자동으로 성립된다.
*/

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
  int answer = 0;

  vector<int> table(10001, 0);

  for (int i = 0; i < citations.size(); ++i) table[citations[i]]++;
  int max = citations.size();

  for (int i = 0; i < table.size(); ++i) {
    if (i <= max) answer = i;

    if (table[i] > 0) max -= table[i];
  }

  return answer;
}