#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
  int answer = 1;

  int temp;
  if (a > b)
    temp = a;
  else
    temp = b;

  for (; temp > 0; --temp) {
    if (a % temp == 0 && b % temp == 0) {
      a /= temp;
      b /= temp;
      break;
    }
  }

  for (int i = 2; i <= b; ++i) {
    if (b % i == 0 && (i != 2 || i != 5)) {
      if (i % 2 == 0 || i % 5 == 0) continue;
      answer = 2;
      break;
    }
  }

  return answer;
}