#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
  bool answer = true;

  int nx = x;
  int dep = 0;
  while (nx) {
    dep += nx % 10;
    nx /= 10;
  }

  if (x % dep != 0) answer = false;

  return answer;
}