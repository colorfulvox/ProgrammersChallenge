#include <cmath>
#include <queue>
#include <string>
#include <vector>

using namespace std;

vector<vector<bool>> map;

int solution(int n, vector<vector<int>> wires) {
  int answer = -1;

  map = vector<vector<bool>>(n + 1, vector<bool>(n + 1, false));
  int cnt = 0;
  for (int w = 0; w < wires.size(); ++w) {
    map[wires[w][0]][wires[w][1]] = map[wires[w][1]][wires[w][0]] = true;
  }
  for (int w = 0; w < wires.size(); ++w) {
    map[wires[w][0]][wires[w][1]] = map[wires[w][1]][wires[w][0]] = false;

    vector<vector<bool>> used(n + 1, vector<bool>(n + 1, false));
    vector<int> ans;

    for (int r = 0; r < n + 1; ++r) {
      int cnt = 0;

      for (int c = 0; c < n + 1; ++c) {
        if (map[r][c] && !used[r][c]) {
          used[r][c] = used[c][r] = true;

          cnt++;
          queue<int> q;
          q.push(c);

          while (q.size()) {
            int t = q.front();
            q.pop();

            for (int i = 0; i < n + 1; ++i) {
              if (map[t][i] && !used[t][i]) {
                used[t][i] = used[i][t] = true;
                ++cnt;
                q.push(i);
              }
            }
          }
        }
      }

      if (cnt != 0) ans.push_back(cnt);
    }
    int res;
    if (ans.size() == 2) {
      res = abs(ans[0] - ans[1]);
    } else
      res = ans[0];

    if (answer == -1 || res < answer) answer = res;

    map[wires[w][0]][wires[w][1]] = map[wires[w][1]][wires[w][0]] = true;
  }

  return answer;
}