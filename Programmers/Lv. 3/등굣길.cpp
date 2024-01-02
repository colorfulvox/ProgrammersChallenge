/*
웅덩이가 없을때 모든 이동하는 경로는 반드시 1이상이다.
1, 1, 1, 1,
1, 2, 3, 4,
1, 3, 6, 10

웅덩이가 0행 or 0열 자리에 있으면 그 다음 위치는 계산할 필요가 없다.
(아래, 오른쪽만 갈 수 있기 때문에)

예시)
[0,1]에 웅덩이가 있을 경우
1, 0, 0, 0, //[0,1]을 0으로 두고 그 이후도 모두 0으로 둔다.
1, 1, 1, 1,
1, 2, 3, 4

ans = 4
*/

#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
  int answer = 0;

  vector<vector<int>> map(n, vector<int>(m, 1));

  for (auto p : puddles) {
    if (p[1] == 1) {
      for (int i = p[0] - 1; i < m; ++i) map[0][i] = 0;
    } else if (p[0] == 1) {
      for (int i = p[1] - 1; i < n; ++i) map[i][0] = 0;
    } else
      map[p[1] - 1][p[0] - 1] = 0;
  }
  for (int r = 1; r < n; ++r) {
    for (int c = 1; c < m; ++c) {
      if (map[r][c] == 0) continue;

      map[r][c] = (map[r - 1][c] + map[r][c - 1]) % 1000000007;
    }
  }
  answer = map[n - 1][m - 1];

  return answer;
}