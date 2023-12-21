#include <string>
#include <vector>

using namespace std;

int answer = 0;
bool flag = false;  // 반복할지 판단

struct pos {
  int y;
  int x;
};

int direct[4][2] = {0, 0, 1, 0, 0, 1, 1, 1};

// 블록 제거
vector<string> removeBlock(int m, int n, vector<string> board) {
  vector<pos> remover;

  for (int r = 0; r < m - 1; ++r) {
    for (int c = 0; c < n - 1; ++c) {
      char target = board[r][c];
      if (target != ' ') {
        if (target == board[r + 1][c] && target == board[r][c + 1] &&
            target == board[r + 1][c + 1]) {
          remover.push_back({r, c});
        }
      }
    }
  }

  for (int r = 0; r < remover.size(); ++r) {
    pos p = remover[r];

    for (int d = 0; d < 4; ++d) {
      int dy = direct[d][0] + p.y;
      int dx = direct[d][1] + p.x;

      if (board[dy][dx] != ' ') {
        ++answer;
        board[dy][dx] = ' ';
      }
    }
  }
  if (remover.size() > 0) flag = true;

  return board;
}

// 블록 이동
vector<string> move(int m, int n, vector<string> board) {
  for (int c = 0; c < n; ++c) {
    for (int r = m - 1; r > 0; --r) {
      int eidx = -1;
      if (board[r][c] == ' ') eidx = r;  // 만약 빈 블록이 있다면 eidx 업데이트

      if (eidx != -1) {  // eidx가 업데이트 되었다면
        bool check = false;
        // eidx 다음으로 빈블록이 아닌것을 찾음
        // check는 만약 빈블록이 없을경우 해당 열의 조사를 모두 중지함
        for (int e = eidx - 1; e >= 0; --e) {
          if (board[e][c] != ' ') {
            check = true;
            char temp = board[e][c];
            board[e][c] = board[eidx][c];
            board[eidx][c] = temp;
            break;
            // 이런식으로 한개씩 빈블록과 아닌 블록을 바꿔줌
          }
        }

        if (!check) break;
      }
    }
  }

  return board;
}

int solution(int m, int n, vector<string> board) {
  while (true) {
    flag = false;

    board = removeBlock(m, n, board);

    if (!flag) break;

    board = move(m, n, board);
  }

  return answer;
}