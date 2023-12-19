#include <string>
#include <vector>

using namespace std;

string solution(string myString, string pat) {
  string answer = "";

  for (int i = 0; i < myString.length(); ++i) {
    if (i + pat.length() <= myString.length()) {
      string temp = myString.substr(i, pat.length());
      if (temp == pat) {
        answer = myString.substr(0, i + pat.length());
      }
    }
  }

  return answer;
}