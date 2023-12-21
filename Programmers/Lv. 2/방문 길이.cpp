/*
-5 -4 -3 -2 -1 0 1 2 3 4 5
0  1  2  3  4 5 6 7 8 9 10

지나간 길인지 확인하기위해서
bool used[11][11][4] 로 정의한다.
4는 U,D,R,L이다.

그리고 현재위치,목표위치의 used의 값을 모두 변경한다.

예를들어,
현재위치에서 위로 간다면 목표위치에서는 아래로 가는 방향을 업데이트한다.
used[cury][curx][U] = true;
used[tary][tarx][D] = true;
*/

#include <string>
#include <vector>
using namespace std;

int solution(string dirs) {
  int answer = 0;

  int direct[4][2] = {
      -1, 0,  // U
      1,  0,  // D
      0,  1,  // R
      0,  -1  // L
  };

  bool used[11][11][4] = {false};

  int y = 5;
  int x = 5;

  for (int i = 0; i < dirs.length(); ++i) {
    int d;
    int t;
    if (dirs[i] == 'U') {
      d = 0;
      t = 1;
    }
    if (dirs[i] == 'D') {
      d = 1;
      t = 0;
    }
    if (dirs[i] == 'R') {
      d = 2;
      t = 3;
    }
    if (dirs[i] == 'L') {
      d = 3;
      t = 2;
    }

    int dy = direct[d][0] + y;
    int dx = direct[d][1] + x;

    if (dy >= 11 || dy < 0 || dx >= 11 || dx < 0) continue;
    if (!used[y][x][d]) {
      used[y][x][d] = true;
      used[dy][dx][t] = true;
      ++answer;
    }
    y = dy;
    x = dx;
  }

  return answer;
}