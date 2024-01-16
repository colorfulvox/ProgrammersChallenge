#include <string>
#include <vector>

using namespace std;

string solution(string s) {
  string answer = "";

  bool flag = true;

  for (auto w : s) {
    if (w == ' ') {
      flag = true;
      answer += ' ';
    } else {
      if (flag) {
        if (w >= 'a' && w <= 'z') w = w - 'a' + 'A';
        answer += w;
        flag = false;
      } else {
        if (w >= 'A' && w <= 'Z') w = w - 'A' + 'a';
        answer += w;
      }
    }
  }

  return answer;
}