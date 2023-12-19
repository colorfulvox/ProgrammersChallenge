// table을 통해 각 위치별로 칠해졌는지 여부를 저장한다.
// 그리고 마지막 위치부터 안 칠해져있을 경우 m 만큼 i를 이동시킨다.
// (table을 업데이트 안하는 이유는 어차피 현재 i에서 i-m+1까지 검사를 안한다.)

#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
  int answer = 0;

  vector<bool> table(n, false);
  for (int s = 0; s < section.size(); ++s) table[section[s] - 1] = true;

  for (int i = n - 1; i >= 0;) {
    if (table[i]) {
      ++answer;
      i = i - m;
    } else
      --i;
  }

  return answer;
}