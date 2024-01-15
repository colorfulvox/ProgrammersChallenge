#include <cmath>
#include <string>
#include <vector>
using namespace std;

long long solution(int k, int d) {
  long long answer = 0;

  long long K = k;
  long long D = d;

  for (long long i = 0;; ++i) {
    if (i * K > D) break;

    long long x = i * k;
    long long limit = sqrt((D * D) - (x * x));

    if (i == 0)
      answer += (limit / k) * 2;
    else
      answer += (limit / k);
  }
  ++answer;
  return answer;
}