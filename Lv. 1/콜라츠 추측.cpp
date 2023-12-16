#include <string>
#include <vector>

using namespace std;

int solution(int num) {
  int answer = -1;
  if (num == 1) return 0;

  long long n = num;

  for (int i = 0; i < 500; ++i) {
    if (n == 1) {
      answer = i;
      break;
    }
    if (n % 2 == 0)
      n /= 2;
    else {
      n *= 3;
      n++;
    }
  }

  return answer;
}