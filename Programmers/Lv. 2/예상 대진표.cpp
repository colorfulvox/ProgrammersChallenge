// [1 2] [3 4] [5 6] [7 8]
//    [1  2]      [3  4]
//          [1  2]
// 2로 나누어 떨어지지 않으면 +1를 한뒤 나눈다.

#include <iostream>

using namespace std;

int solution(int n, int a, int b) {
  int answer = 0;

  int round = 0;

  while (true) {
    if (a == b) break;
    if (a % 2 != 0) {
      ++a;
      a /= 2;
    } else
      a /= 2;

    if (b % 2 != 0) {
      ++b;
      b /= 2;
    } else
      b /= 2;
    ++round;
  }

  answer = round;

  return answer;
}