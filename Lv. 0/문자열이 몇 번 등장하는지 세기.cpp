#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
  int answer = 0;

  for (int i = 0; i < myString.length(); ++i) {
    if (i + pat.length() <= myString.length()) {
      string temp = myString.substr(i, pat.length());
      if (temp == pat) ++answer;
    }
  }

  return answer;
}