#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
  string answer = "";

  for (auto str = s.begin(); str < s.end(); ++str) {
    if (*str != ' ') {
      if (*str >= 'A' && *str <= 'Z') {
        if (*str + n > 'Z')
          answer += (*str + n) - 'Z' + 'A' - 1;
        else
          answer += *str + n;
      } else if (*str >= 'a' && *str <= 'z') {
        if (*str + n > 'z')
          answer += (*str + n) - 'z' + 'a' - 1;
        else
          answer += *str + n;
      }
    } else
      answer += *str;
  }

  return answer;
}