#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
  int answer = 21e8;

  vector<vector<int>> map(n + 1, vector<int>(n + 1, 100001 * n));

  for (auto fa : fares) {
    map[fa[0]][fa[1]] = fa[2];
    map[fa[1]][fa[0]] = fa[2];
  }

  for (int k = 1; k < n + 1; ++k) {
    for (int i = 1; i < n + 1; ++i) {
      for (int j = 1; j < n + 1; ++j) {
        if (i == j) map[i][j] = 0;
        if (map[i][j] > map[i][k] + map[k][j])
          map[i][j] = map[i][k] + map[k][j];
      }
    }
  }

  for (int x = 1; x < n + 1; ++x) {
    if (answer > map[s][x] + map[x][a] + map[x][b])
      answer = map[s][x] + map[x][a] + map[x][b];
  }

  return answer;
}