#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
  long long answer = 0;

  int dat[10] = {0};

  while (n) {
    dat[n % 10]++;
    n /= 10;
  }
  long long dig = 1;
  for (int i = 0; i < 10; ++i) {
    while (dat[i]--) {
      if (i == 0)
        dig *= 10;
      else {
        answer += i * dig;
        dig *= 10;
      }
    }
  }

  return answer;
}