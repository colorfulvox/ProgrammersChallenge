#include <string>
#include <vector>

using namespace std;

string solution(string s) {
  string answer = "";

  int max = -21e8;
  int min = 21e8;

  string temp = "";
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == ' ' || i + 1 == s.length()) {
      if (i + 1 == s.length()) temp += s[i];
      int n = stoi(temp);
      temp = "";
      if (max < n) max = n;
      if (min > n) min = n;

    } else
      temp += s[i];
  }
  answer = to_string(min) + ' ' + to_string(max);

  return answer;
}