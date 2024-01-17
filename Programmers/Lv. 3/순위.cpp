#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
  int answer = 0;

  vector<vector<int>> table(n + 1, vector<int>(n + 1, 0));

  for (auto re : results) {
    int win = re[0];
    int lose = re[1];

    table[win][lose] = 1;
    table[lose][win] = -1;
  }

  for (int r = 1; r <= n; ++r) {
    int idx = r;
    vector<bool> used(n + 1, false);

    used[idx] = true;

    queue<int> q;
    for (int i = 1; i <= n; ++i)  // 이긴 녀석들을 선별한다.
    {
      if (table[idx][i] == 0) continue;

      if (table[idx][i] == 1) {
        q.push(i);
        used[i] = true;
      }
    }

    while (q.size())  // 이긴 녀석들 중에서 걔한테 진애들을 업데이트한다.
    {
      int p = q.front();
      q.pop();

      for (int i = 1; i <= n; ++i) {
        if (used[i]) continue;

        if (table[p][i] == 1) {
          table[idx][i] = 1;
          table[i][idx] = -1;
          q.push(i);
          used[i] = true;
        }
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    int cnt = 0;
    for (int j = 1; j <= n; ++j) {
      if (table[i][j] != 0) ++cnt;
    }
    if (cnt == n - 1) ++answer;
  }

  return answer;
}