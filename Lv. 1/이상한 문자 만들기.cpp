#include <string>
#include <vector>

using namespace std;

string solution(string s) {
  string answer = "";
  int idx = 0;

  for (int i = 0; i < s.length(); ++i) {
    if (s[i] != ' ') {
      if (idx % 2 == 0) {
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
      ++idx;
    } else {
      idx = 0;
      answer += s[i];
    }
  }

  return answer;
}