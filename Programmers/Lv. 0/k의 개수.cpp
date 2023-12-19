#include <string>
#include <vector>

using namespace std;

int solution(int i, int j, int k) {
  int answer = 0;

  while (i <= j) {
    int n = i;

    while (n) {
      int temp = n % 10;
      if (temp == k) ++answer;
      n /= 10;
    }
    ++i;
  }

  return answer;
}