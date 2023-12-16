#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string overwrite_string, int s) {
  string answer = "";

  for (int i = 0; i < my_string.length(); ++i) {
    if (s == i) {
      answer += overwrite_string;
      i += overwrite_string.length() - 1;
    } else
      answer += my_string[i];
  }

  return answer;
}