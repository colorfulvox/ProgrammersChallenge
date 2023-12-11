#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
  int answer = 0;

  for (auto p = pat.begin(); p < pat.end(); ++p) {
    if (*p == 'A')
      *p = 'B';
    else
      *p = 'A';
  }

  for (int i = 0; i < myString.length() - pat.length() + 1; ++i) {
    string temp = myString.substr(i, pat.length());
    if (temp == pat) answer = 1;
  }

  return answer;
}