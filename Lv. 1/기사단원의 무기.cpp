#include <cmath>
#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
  int answer = 0;

  for (int n = 1; n <= number; ++n) {
    int cnt = 0;
    for (int i = 1; i <= sqrt(n); ++i) {
      if (n % i == 0) {
        if (i != n / i) ++cnt;
        ++cnt;
      }
    }
    if (cnt > limit)
      answer += power;
    else
      answer += cnt;
  }

  return answer;
}