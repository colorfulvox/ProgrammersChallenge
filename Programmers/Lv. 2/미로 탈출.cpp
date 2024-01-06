#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct pos {
  int y;
  int x;
  int move;
};

int direct[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int n, m;
int sy, sx;
int ly, lx;

vector<string> mapss;

int func(int y, int x, char target) {
  queue<pos> q;
  vector<vector<bool>> used(n, vector<bool>(m, false));
  q.push({y, x, 0});
  used[y][x] = true;

  while (q.size()) {
    pos p = q.front();
    q.pop();
    p.move++;

    for (int d = 0; d < 4; ++d) {
      int dy = direct[d][0] + p.y;
      int dx = direct[d][1] + p.x;
      if (dy >= n || dy < 0 || dx >= m || dx < 0) continue;
      if (used[dy][dx] || mapss[dy][dx] == 'X') continue;

      if (mapss[dy][dx] == target) return p.move;
      used[dy][dx] = true;

      q.push({dy, dx, p.move});
    }
  }

  return -1;
}

int solution(vector<string> maps) {
  int answer = -1;

  n = maps.size();
  m = maps[0].length();

  mapss = vector<string>(maps.begin(), maps.end());

  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < m; ++c) {
      if (maps[r][c] == 'S') {
        sy = r;
        sx = c;
      }
      if (maps[r][c] == 'L') {
        ly = r;
        lx = c;
      }
    }
  }
  answer = func(sy, sx, 'L');

  if (answer != -1) {
    int temp = func(ly, lx, 'E');
    if (temp == -1)
      answer = -1;
    else
      answer += temp;
  }
  return answer;
}