#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
  vector<int> answer;

  int rlan = park.size();
  int clan = park[0].size();

  int direct[4][2] = {
      -1, 0,   // N
      1,  0,   // S
      0,  -1,  // W
      0,  1    // E
  };

  int cury;
  int curx;

  for (int r = 0; r < rlan; ++r) {
    for (int c = 0; c < clan; ++c) {
      if (park[r][c] == 'S') {
        cury = r;
        curx = c;
      }
    }
  }

  for (int r = 0; r < routes.size(); ++r) {
    char cmd = routes[r][0];
    int move = stoi(routes[r].substr(2));

    int d;
    if (cmd == 'N') d = 0;
    if (cmd == 'S') d = 1;
    if (cmd == 'W') d = 2;
    if (cmd == 'E') d = 3;

    int tcury = cury;
    int tcurx = curx;

    bool flag = true;

    for (int m = 0; m < move; ++m) {
      int dy = direct[d][0] + tcury;
      int dx = direct[d][1] + tcurx;

      if (dy >= rlan || dy < 0 || dx >= clan || dx < 0) {
        flag = false;
        break;
      }
      if (park[dy][dx] == 'X') {
        flag = false;
        break;
      }

      tcury = dy;
      tcurx = dx;
    }
    if (flag) {
      cury = tcury;
      curx = tcurx;
    }
  }
  answer.push_back(cury);
  answer.push_back(curx);

  return answer;
}