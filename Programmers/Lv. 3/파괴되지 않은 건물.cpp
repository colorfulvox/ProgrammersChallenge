// 누적합 문제
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
  int answer = 0;

  int n = board.size();
  int m = board[0].size();

  vector<vector<int>> table(n, vector<int>(m, 0));

  for (auto sk : skill) {
    if (sk[0] == 1) sk[5] *= -1;

    table[sk[1]][sk[2]] += sk[5];
    if (sk[4] + 1 < m) table[sk[1]][sk[4] + 1] += -sk[5];
    if (sk[3] + 1 < n) table[sk[3] + 1][sk[2]] += -sk[5];
    if (sk[3] + 1 < n && sk[4] + 1 < m) table[sk[3] + 1][sk[4] + 1] += sk[5];
  }

  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < m; ++c) {
      if (c != 0) table[r][c] += table[r][c - 1];
    }
  }

  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < m; ++c) {
      if (r != 0) table[r][c] += table[r - 1][c];
    }
  }
  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < m; ++c) {
      board[r][c] += table[r][c];
      if (board[r][c] > 0) ++answer;
    }
  }

  return answer;
}