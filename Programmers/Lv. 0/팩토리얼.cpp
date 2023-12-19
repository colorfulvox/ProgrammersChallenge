#include <string>
#include <vector>

using namespace std;

int solution(int n) {
  int answer = 0;

  int a = 1;
  for (int i = 1; i <= 10; ++i) {
    if (a * i <= n) {
      answer = i;
    }
    a *= i;
  }

  return answer;
}