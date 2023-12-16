#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
  vector<vector<int>> answer(n, vector<int>(n, -1));

  int num = 1;
  int y = 0;
  int x = 0;
  int bang = 0;
  while (true) {
    answer[y][x] = num++;
    if (n == 1) break;

    if (bang == 0) {
      if (x + 1 >= n || answer[y][x + 1] != -1) {
        bang = 1;
        ++y;
      } else
        ++x;
    }

    else if (bang == 1) {
      if (y + 1 >= n || answer[y + 1][x] != -1) {
        bang = 2;
        --x;
      } else
        ++y;
    } else if (bang == 2) {
      if (x - 1 < 0 || answer[y][x - 1] != -1) {
        bang = 3;
        --y;
      } else
        --x;
    } else if (bang == 3) {
      if (y - 1 < 0 || answer[y - 1][x] != -1) {
        bang = 0;
        ++x;
      } else
        --y;
    }

    if (answer[y][x] != -1) break;
  }

  return answer;
}