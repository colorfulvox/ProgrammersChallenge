/*
1. 여벌 옷이 있는 사람이 옷을 도난 당했을 수도 있다.
그래서 real_reserve에 진.짜.로 빌려줄 수 있는 사람을 다시 선별해 저장한다.

2. reserve는 정렬이 되어 있지 않다.
만약 [5,3]로 들어있고 6번 사람이 옷이 없다면 5번이 6번에게 줘야한다.
하지만 만약 4도 옷이 없다면 첫번째 5는 4번을 주고 3번은 아무에게도 못준다.
그래서 정렬해서 모두에게 줄 수 있도록 한다.
*/

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
  int answer = n;

  vector<bool> table(n + 1, true);
  vector<int> real_reserve;

  for (int i = 0; i < lost.size(); ++i) {
    table[lost[i]] = false;
    --answer;
  }
  for (int i = 0; i < reserve.size(); ++i) {
    if (!table[reserve[i]]) {
      table[reserve[i]] = true;
      ++answer;
    } else
      real_reserve.push_back(reserve[i]);
  }
  sort(real_reserve.begin(), real_reserve.end());

  for (int i = 0; i < real_reserve.size(); ++i) {
    int be = real_reserve[i] - 1;
    if (be > 0 && !table[be]) {
      table[be] = true;
      ++answer;
      continue;
    }
    int af = real_reserve[i] + 1;
    if (af < n + 1 && !table[af]) {
      table[af] = true;
      ++answer;
      continue;
    }
  }

  return answer;
}