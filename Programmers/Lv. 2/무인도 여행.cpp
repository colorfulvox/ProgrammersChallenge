#include <algorithm>
#include <queue>
#include <string>
#include <vector>

using namespace std;

vector<int> answer;

struct pos {
  int y;
  int x;
};

vector<vector<bool>> used(101, vector<bool>(101, false));

vector<string> map;

int direct[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};

void func(int y, int x) {
  int n = map.size();
  int m = map[0].length();
  int cnt = map[y][x] - '0';
  used[y][x] = true;
  queue<pos> q;
  q.push({y, x});

  while (q.size()) {
    pos p = q.front();
    q.pop();

    for (int d = 0; d < 4; ++d) {
      int dy = direct[d][0] + p.y;
      int dx = direct[d][1] + p.x;

      if (dy >= n || dy < 0 || dx >= m || dx < 0) continue;
      if (used[dy][dx] || map[dy][dx] == 'X') continue;
      used[dy][dx] = true;
      cnt += map[dy][dx] - '0';
      q.push({dy, dx});
    }
  }
  answer.push_back(cnt);
}

vector<int> solution(vector<string> maps) {
  map = maps;

  for (int r = 0; r < map.size(); ++r) {
    for (int c = 0; c < map[r].size(); ++c) {
      if (map[r][c] != 'X' && !used[r][c]) func(r, c);
    }
  }

  if (!answer.size())
    answer.push_back(-1);
  else
    sort(answer.begin(), answer.end());
  return answer;
}