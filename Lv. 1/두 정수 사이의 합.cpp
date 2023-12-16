#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
  long long answer = 0;

  if (a > b) {
    int tm = a;
    a = b;
    b = tm;
  }

  for (; a <= b; ++a) answer += a;

  return answer;
}