#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
  vector<int> answer;

  int cury = 0;
  int curx = 0;
  int direct[4][2] = {1, 0, -1, 0, 0,
                      1, 0, -1

  };

  for (auto cmd = keyinput.begin(); cmd < keyinput.end(); ++cmd) {
    int d;
    if (*cmd == "up")
      d = 0;
    else if (*cmd == "down")
      d = 1;
    else if (*cmd == "right")
      d = 2;
    else if (*cmd == "left")
      d = 3;

    int dy = direct[d][0] + cury;
    int dx = direct[d][1] + curx;

    if (dy > board[1] / 2 || dy < -(board[1] / 2) || dx > board[0] / 2 ||
        dx < -(board[0] / 2))
      continue;

    cury = dy;
    curx = dx;
  }
  answer.push_back(curx);
  answer.push_back(cury);

  return answer;
}