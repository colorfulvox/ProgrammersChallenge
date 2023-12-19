#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
  bool answer = true;

  if (s.length() != 4 && s.length() != 6) answer = false;
  for (auto str = s.begin(); str < s.end(); ++str) {
    if (*str >= '0' && *str <= '9') continue;
    answer = false;
    break;
  }

  return answer;
}