#include <string>
#include <vector>

using namespace std;

string convert(string target) {
  string temp = "";
  for (auto t = target.begin(); t < target.end(); ++t) {
    if (*t >= 'A' && *t <= 'Z')
      temp += *t - 'A' + 'a';
    else
      temp += *t;
  }
  return temp;
}

int solution(string myString, string pat) {
  int answer = 0;

  myString = convert(myString);
  pat = convert(pat);

  for (int i = 0; i < myString.length(); ++i) {
    if (i + pat.length() <= myString.length()) {
      string temp = myString.substr(i, pat.length());
      if (temp == pat) answer = 1;
    }
  }

  return answer;
}