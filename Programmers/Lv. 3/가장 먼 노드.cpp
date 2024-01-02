#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool compare(int a, int b) { return a > b; }

int solution(int n, vector<vector<int>> edge) {
  int answer = 0;

  vector<vector<int>> map(n + 1, vector<int>(n + 1, 21e8));

  for (auto e : edge) {
    map[e[0]][e[1]] = map[e[1]][e[0]] = 1;
  }

  vector<int> dist(n + 1, 21e8);
  vector<bool> used(n + 1, false);

  for (int i = 1; i < n + 1; ++i) dist[i] = map[1][i];
  dist[1] = 0;
  used[1] = true;

  for (int i = 1; i < n + 1; ++i) {
    int min = 21e8;
    int idx = 0;

    for (int d = 1; d < n + 1; ++d) {
      if (dist[d] < min && !used[d]) {
        min = dist[d];
        idx = d;
      }
    }

    used[idx] = true;
    for (int j = 1; j < n + 1; ++j) {
      if (!used[j]) {
        if (dist[idx] + map[idx][j] < dist[j]) {
          dist[j] = dist[idx] + map[idx][j];
        }
      }
    }
  }

  sort(dist.begin(), dist.end(), compare);

  int num = dist[1];
  for (int d = 1; d < n + 1; ++d) {
    if (dist[d] != num) break;
    ++answer;
  }

  return answer;
}