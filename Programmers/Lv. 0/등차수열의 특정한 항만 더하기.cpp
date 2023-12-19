#include <string>
#include <vector>

using namespace std;

int solution(int a, int d, vector<bool> included) {
  int answer = 0;

  for (auto flag = included.begin(); flag < included.end(); ++flag) {
    if (*flag) {
      answer += a;
    }
    a += d;
  }

  return answer;
}