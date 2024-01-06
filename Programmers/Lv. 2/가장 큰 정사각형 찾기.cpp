#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board) {
  int answer = 0;

  vector<vector<int>> dp(board.size() + 1, vector<int>(board[0].size() + 1, 0));

  for (int r = 1; r < board.size() + 1; ++r) {
    for (int c = 1; c < board[0].size() + 1; ++c) {
      if (board[r - 1][c - 1] == 1) {
        int MIN = 21e8;
        if (dp[r - 1][c] < MIN) MIN = dp[r - 1][c];
        if (dp[r][c - 1] < MIN) MIN = dp[r][c - 1];
        if (dp[r - 1][c - 1] < MIN) MIN = dp[r - 1][c - 1];
        dp[r][c] = MIN + 1;
        if (dp[r][c] > answer) answer = dp[r][c];
      }
    }
  }
  answer = answer * answer;

  return answer;
}