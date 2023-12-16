#include <cmath>
#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
  long long answer = -1;

  long long sq = sqrt(n);

  if (n == sq * sq) answer = pow(sq + 1, 2);

  return answer;
}

/*
#include <string>

using namespace std;

long long solution(long long n) {
    long long answer = -1;

    long long x = 0;

    while(x * x < n)x++;

    if(x * x == n)answer = (x+1) * (x+1);

    return answer;
}
*/