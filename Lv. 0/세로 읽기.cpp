#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int m, int c) {
  string answer = "";

  for (int i = 0; i < my_string.length(); i += m) {
    if (i + m <= my_string.length()) {
      string temp = my_string.substr(i, m);
      answer += temp[c - 1];
    }
  }

  return answer;
}