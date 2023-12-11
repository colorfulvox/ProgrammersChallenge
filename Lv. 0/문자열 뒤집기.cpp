#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string solution(string my_string, int s, int e) {
  string answer = "";
  string temp = my_string.substr(s, e - s + 1);
  reverse(temp.begin(), temp.end());

  for (int i = 0; i < my_string.length(); ++i) {
    if (i == s) {
      answer += temp;
      i = e;
    } else
      answer += my_string[i];
  }

  return answer;
}