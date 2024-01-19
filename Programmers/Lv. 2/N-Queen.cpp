#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> map;
vector<bool> used;

int answer = 0;
int limit;

int direct[4][2] = {1, 1, 1, -1, -1, 1, -1, -1};

void func(int level) {
  if (level == limit) {
    // for (int r = 0; r < limit; ++r)
    //{
    //     for (int c = 0; c < limit; ++c)cout << map[r][c] << " ";
    //     cout << endl;
    // }
    // cout << endl;
    ++answer;

    return;
  }

  for (int j = 0; j < limit; ++j) {
    if (used[j]) continue;

    bool flag = true;

    for (int d = 0; d < 4; ++d) {
      int dy = level + direct[d][0];
      int dx = j + direct[d][1];

      while (dy >= 0 && dy < limit && dx >= 0 && dx < limit) {
        if (map[dy][dx]) {
          flag = false;
          break;
        }
        dy += direct[d][0];
        dx += direct[d][1];
      }
      if (!flag) break;
    }
    if (!flag) continue;

    used[j] = true;
    map[level][j] = 1;
    func(level + 1);
    map[level][j] = 0;
    used[j] = false;
  }
}

int solution(int n) {
  limit = n;
  map = vector<vector<int>>(n, vector<int>(n, 0));
  used = vector<bool>(n, false);
  func(0);

  return answer;
}