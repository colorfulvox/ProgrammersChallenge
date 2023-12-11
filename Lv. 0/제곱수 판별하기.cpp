#include <cmath>
#include <string>
#include <vector>
using namespace std;

int solution(int n) {
  int answer = int(sqrt(n)) * int(sqrt(n)) == n ? 1 : 2;
  return answer;
}