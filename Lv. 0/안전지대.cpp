#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board) {
  int answer = board.size() * board[0].size();

  vector<vector<bool>> used(board.size(), vector<bool>(board[0].size(), false));

  int direct[8][2] = {0, 1, 0, -1, 1, 0, -1, 0, 1, 1, 1, -1, -1, 1, -1, -1};

  for (int r = 0; r < board.size(); ++r) {
    for (int c = 0; c < board[r].size(); ++c) {
      if (board[r][c] == 1) {
        if (!used[r][c]) {
          --answer;
          used[r][c] = true;
        }
        for (int d = 0; d < 8; ++d) {
          int dy = direct[d][0] + r;
          int dx = direct[d][1] + c;

          if (dy < 0 || dy >= board.size() || dx < 0 || dx >= board[r].size())
            continue;
          if (used[dy][dx]) continue;
          used[dy][dx] = true;
          --answer;
        }
      }
    }
  }

  return answer;
}