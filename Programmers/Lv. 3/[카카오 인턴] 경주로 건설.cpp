/*
1. 비용을 기준으로 탐색한다.
2. 단, 0,0 - n,m까지 탐색한 결과와 n,m - 0,0 까지
탐색한 결과가 다를 경우가 있다.
3. 그래서 0,0 - n,m 과 n,m - 0,0을 탐색해서 제일 작은 것을 찾아야 한다.
*/

#include <queue>
#include <string>
#include <vector>

using namespace std;

struct pos {
  int y;
  int x;
  int before;
  int cost;
};

int direct[4][2] = {
    0,  1,   // 0
    0,  -1,  // 1
    1,  0,   // 2
    -1, 0    // 3
};

int solution(vector<vector<int>> board) {
  int answer = 0;

  int n = board.size();
  int m = board[0].size();

  vector<vector<int>> costmap(n, vector<int>(m, 21e8));

  costmap[0][0] = 0;
  queue<pos> q;
  q.push({0, 0, -1, 0});

  while (q.size()) {
    pos p = q.front();

    int before = p.before;

    q.pop();
    if (p.y == n - 1 && p.x == m - 1) continue;
    for (int d = 0; d < 4; ++d) {
      int cost = p.cost + 100;
      int dy = direct[d][0] + p.y;
      int dx = direct[d][1] + p.x;
      if (dy >= n || dy < 0 || dx >= m || dx < 0) continue;
      if (board[dy][dx] == 1) {
        costmap[dy][dx] = 0;
        continue;
      }
      // 코너 검사
      if ((d == 0 || d == 1) && (before == 2 || before == 3))
        cost += 500;
      else if ((d == 2 || d == 3) && (before == 0 || before == 1))
        cost += 500;

      if (costmap[dy][dx] < cost) continue;

      costmap[dy][dx] = cost;
      q.push({dy, dx, d, cost});
    }
  }
  answer = costmap[n - 1][m - 1];

  q.push({n - 1, m - 1, -1, 0});
  costmap = vector<vector<int>>(n, vector<int>(m, 21e8));
  costmap[n - 1][m - 1] = 0;

  while (q.size()) {
    pos p = q.front();

    int before = p.before;

    q.pop();
    if (p.y == 0 && p.x == 0) continue;
    for (int d = 0; d < 4; ++d) {
      int cost = p.cost + 100;
      int dy = direct[d][0] + p.y;
      int dx = direct[d][1] + p.x;
      if (dy >= n || dy < 0 || dx >= m || dx < 0) continue;
      if (board[dy][dx] == 1) {
        costmap[dy][dx] = 0;
        continue;
      }
      // 코너 검사
      if ((d == 0 || d == 1) && (before == 2 || before == 3))
        cost += 500;
      else if ((d == 2 || d == 3) && (before == 0 || before == 1))
        cost += 500;

      if (costmap[dy][dx] < cost) continue;

      costmap[dy][dx] = cost;
      q.push({dy, dx, d, cost});
    }
  }
  if (answer > costmap[0][0]) answer = costmap[0][0];

  return answer;
}