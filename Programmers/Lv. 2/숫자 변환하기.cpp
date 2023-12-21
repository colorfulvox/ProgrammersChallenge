/*
처음 위치 x의 이동거리를 0으로 두고
x 에서 y-1까지 이동하면서
x 부터 +n, *2, *3을 한 위치에 대한 업데이트를 진행한다.

업데이트는 현재 위치값이 -1이 아닐때 그리고
만약 업데이트 되었다면 이동한 거리가 더 클 경우 업데이트한다.
*/

#include <string>
#include <vector>

using namespace std;

int solution(int x, int y, int n) {
  int answer = -1;

  vector<int> table(y + 1, -1);

  table[x] = 0;

  for (int i = x; i < y; ++i) {
    int cnt = table[i];
    if (cnt == -1) continue;

    if (i + n <= y) {
      if (table[i + n] == -1 || table[i + n] > cnt + 1) table[i + n] = cnt + 1;
    }

    if (i * 2 <= y) {
      if (table[i * 2] == -1 || table[i * 2] > cnt + 1) table[i * 2] = cnt + 1;
    }

    if (i * 3 <= y) {
      if (table[i * 3] == -1 || table[i * 3] > cnt + 1) table[i * 3] = cnt + 1;
    }
  }
  answer = table[y];

  return answer;
}