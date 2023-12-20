#include <string>
#include <vector>

using namespace std;

int countfunc(int n) {
  int cnt = 0;
  while (n) {
    if (n % 2 == 1) ++cnt;
    n /= 2;
  }
  return cnt;
}

int solution(int n) {
  int answer = 0;

  int ncnt = countfunc(n);

  while (true) {
    ++n;
    if (ncnt == countfunc(n)) {
      answer = n;
      break;
    }
  }

  return answer;
}