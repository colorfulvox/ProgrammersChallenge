#include <string>
#include <vector>

using namespace std;

string solution(string s) {
  string answer = "";

  bool flag = true;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == ' ') {
      flag = true;
      answer += ' ';
    } else if (flag) {
      flag = false;
      if (s[i] >= 'a' && s[i] <= 'z')
        answer += s[i] - 'a' + 'A';
      else
        answer += s[i];
    } else {
      if (s[i] >= 'A' && s[i] <= 'Z')
        answer += s[i] - 'A' + 'a';
      else
        answer += s[i];
    }
  }

  return answer;
}