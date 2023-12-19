#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> result;
vector<vector<bool>> used;
vector<string> map;

int direct[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

struct pos {
  int y;
  int x;
};

void func(int r, int c) {
  int cnt = 1;
  used[r][c] = true;
  queue<pos> q;
  q.push({r, c});

  while (!q.empty()) {
    pos p = q.front();
    q.pop();

    for (int d = 0; d < 4; ++d) {
      int dy = direct[d][0] + p.y;
      int dx = direct[d][1] + p.x;

      if (dy >= map.size() || dy < 0 || dx >= map.size() || dx < 0) continue;
      if (used[dy][dx] || map[dy][dx] == '0') continue;
      used[dy][dx] = true;
      ++cnt;
      q.push({dy, dx});
    }
  }

  result.push_back(cnt);
}

int main(int argc, char** argv) {
  int n;
  cin >> n;

  used = vector<vector<bool>>(n, vector<bool>(n, false));
  while (n--) {
    string temp;
    cin >> temp;
    map.push_back(temp);
  }

  for (int r = 0; r < map.size(); ++r) {
    for (int c = 0; c < map[r].length(); ++c) {
      if (!used[r][c] && map[r][c] == '1') func(r, c);
    }
  }

  sort(result.begin(), result.end());

  cout << result.size() << endl;
  for (int r = 0; r < result.size(); ++r) {
    cout << result[r] << endl;
  }

  return 0;
}