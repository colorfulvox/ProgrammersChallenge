/*
n = 4
1
2 9
3 10 8
4 5  6 7

첫번째 행동 1,0
두번째 0,1
세번째 -1,-1

해당 행동들을 수행할때 n과 같거나, 0보다 작으면
그리고 이미 mat에 수가 저장되어 있다면 다음 행동으로 업데이트
업데이트한 행동도 조건에 걸리면 탈출

*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
  vector<int> answer;

  vector<vector<int>> mat(n, vector<int>(n, 0));

  int direct[3][2] = {1, 0, 0, 1, -1, -1};

  int b = 0;

  int y = 0, x = 0;

  int num = 1;
  while (true) {
    mat[y][x] = num++;

    int dy = direct[b][0] + y;
    int dx = direct[b][1] + x;
    if (dy >= n || dy < 0 || dx >= n || dx < 0 || mat[dy][dx] != 0) {
      b++;
      if (b == 3) b = 0;
      dy = direct[b][0] + y;
      dx = direct[b][1] + x;
      if (mat[dy][dx] != 0) break;
    }
    y = dy;
    x = dx;
  }

  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < n; ++c) {
      if (mat[r][c]) answer.push_back(mat[r][c]);
    }
  }

  return answer;
}