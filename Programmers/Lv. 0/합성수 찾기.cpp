#include <string>
#include <vector>

using namespace std;

int solution(int n) {
  int answer = 0;

  while (n > 3) {
    for (int i = 2; i < n; ++i) {
      if (n % i == 0) {
        ++answer;
        break;
      }
    }
    --n;
  }
  return answer;
}