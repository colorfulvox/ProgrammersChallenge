#include <queue>
#include <string>
#include <vector>

using namespace std;

int direct[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

struct pos {
  int y;
  int x;
  int move;
};

vector<string> map;
int n;
int m;
int sy, sx;

vector<vector<bool>> used;
int answer = -1;

void func() {
  queue<pos> q;
  used[sy][sx] = true;
  q.push({sy, sx, 0});

  while (q.size()) {
    pos p = q.front();
    q.pop();
    int move = p.move + 1;

    for (int d = 0; d < 4; ++d) {
      int y = p.y;
      int x = p.x;

      while (true) {
        y += direct[d][0];
        x += direct[d][1];
        if (y >= n || y < 0 || x >= m || x < 0) break;
        if (map[y][x] == 'D') break;
      }
      y -= direct[d][0];
      x -= direct[d][1];
      if (map[y][x] == 'G') {
        answer = move;
        return;
      }
      if (used[y][x]) continue;
      used[y][x] = true;
      q.push({y, x, move});
    }
  }
}

int solution(vector<string> board) {
  n = board.size();
  m = board[0].length();
  map = vector<string>(board.begin(), board.end());

  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < m; ++c) {
      if (map[r][c] == 'R') {
        sy = r;
        sx = c;
      }
    }
  }
  used = vector<vector<bool>>(n, vector<bool>(m, false));

  func();

  return answer;
}