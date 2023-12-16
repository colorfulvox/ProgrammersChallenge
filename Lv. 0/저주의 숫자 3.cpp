#include <string>
#include <vector>

using namespace std;

bool check(int answer) {
  int num = answer;
  if (num % 3 == 0) return false;

  while (num) {
    if (num % 10 == 3) return false;
    num /= 10;
  }

  return true;
}

int solution(int n) {
  int answer = 0;

  for (int i = 1; i <= n; ++i) {
    ++answer;
    while (true) {
      if (!check(answer))
        ++answer;
      else
        break;
    }
  }

  return answer;
}