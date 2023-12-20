/*
1. 홀수 일때는 어쨋든 무조건 1번은 1칸을 이동하기에 홀수 일 경우 ++ans 해준다.
2. 그리고 짝수, 홀수 상관없이 n/2를 해가며
만약 n/2값이 홀수 일경우 ++ans를 하고 n를 1감소시켜 짝수로 만들어준다.
*/

#include <iostream>
using namespace std;

int solution(int n) {
  int ans = 0;
  if (n % 2 != 0) ++ans;

  while (n > 0) {
    n /= 2;
    if (n % 2 != 0) {
      --n;
      ++ans;
    }
  }

  return ans;
}