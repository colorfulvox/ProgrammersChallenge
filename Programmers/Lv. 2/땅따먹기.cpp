#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int> > land) {
  int answer = -21e8;

  for (int r = 1; r < land.size(); ++r) {
    for (int c = 0; c < 4; ++c) {
      int MAX = -21e8;  // r-1과 합할때 가장 큰것을 고르기 위한 변수

      for (int t = 0; t < 4; ++t) {
        if (t == c) continue;  // 만약 r-1과 r의 열이 같으면 무시한다.

        if (MAX < land[r][c] + land[r - 1][t])
          MAX = land[r][c] + land[r - 1][t];
      }
      land[r][c] = MAX;  // 현재 r,c를 MAX로 업데이트한다.
    }
  }

  for (int i = 0; i < 4; ++i) {
    if (answer < land[land.size() - 1][i]) answer = land[land.size() - 1][i];
  }

  return answer;
}