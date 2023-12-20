#include <queue>
#include <vector>
using namespace std;

int answer = -1;

struct pos {
  int y;
  int x;
  int level;
};

int direct[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

vector<vector<bool>> used;

void func(vector<vector<int>> maps) {
  int n = maps.size();
  int m = maps[0].size();
  vector<vector<bool>> used(n, vector<bool>(m, false));
  queue<pos> q;
  q.push({0, 0, 1});
  used[0][0] = true;

  while (!q.empty()) {
    pos p = q.front();
    q.pop();
    int level = p.level + 1;

    for (int d = 0; d < 4; ++d) {
      int dy = direct[d][0] + p.y;
      int dx = direct[d][1] + p.x;
      if (dy >= n || dy < 0 || dx >= m || dx < 0) continue;
      if (used[dy][dx]) continue;
      if (maps[dy][dx] == 0) continue;

      if (dy == n - 1 && dx == m - 1) {
        if (answer == -1 || answer > level) answer = level;
      } else {
        used[dy][dx] = true;
        q.push({dy, dx, level});
      }
    }
  }
}

int solution(vector<vector<int>> maps) {
  func(maps);

  return answer;
}