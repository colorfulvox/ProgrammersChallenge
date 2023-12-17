#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
  int answer = 0;

  string target = board[h][w];
  int direct[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

  for (int d = 0; d < 4; ++d) {
    int dy = direct[d][0] + h;
    int dx = direct[d][1] + w;

    if (dy >= board.size() || dy < 0 || dx >= board[0].size() || dx < 0)
      continue;
    if (board[dy][dx] == target) ++answer;
  }

  return answer;
}