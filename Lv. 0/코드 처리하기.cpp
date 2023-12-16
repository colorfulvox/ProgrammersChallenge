#include <string>
#include <vector>

using namespace std;

string solution(string code) {
  string answer = "";
  bool mode = false;
  for (int i = 0; i < code.length(); ++i) {
    if (code[i] == '1')
      mode = !mode;
    else {
      if (!mode) {
        if (i % 2 == 0) answer += code[i];
      } else {
        if (i % 2 != 0) answer += code[i];
      }
    }
  }
  if (!answer.length()) answer = "EMPTY";

  return answer;
}