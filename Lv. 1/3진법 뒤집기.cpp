#include <cmath>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
  long long answer = 0;

  long long temp = 0;
  long long dig = 1;

  while (n) {
    temp += (n % 3) * dig;
    dig *= 10;
    n /= 3;
  }
  bool first = true;
  int thre = 1;
  dig /= 10;

  while (temp) {
    if (first) {
      first = false;
      answer += temp / dig;
    } else {
      answer += (temp / dig) * pow(3, thre);
      thre++;
    }
    temp %= dig;
    dig /= 10;
  }

  return answer;
}