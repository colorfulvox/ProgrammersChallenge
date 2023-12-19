#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
  int answer = 0;

  bool flag = true;

  bool plus = false;
  bool minus = false;

  string temp = "";
  for (auto str = my_string.begin(); str < my_string.end(); ++str) {
    if (*str == ' ') {
      if (temp.length()) {
        if (flag) {
          answer += stoi(temp);
          temp = "";
          flag = false;
        } else if (minus) {
          answer -= stoi(temp);
          temp = "";
          minus = false;
        } else if (plus) {
          answer += stoi(temp);
          temp = "";
          plus = false;
        }
      }
    } else if (*str == '+')
      plus = true;
    else if (*str == '-')
      minus = true;
    else if (*str >= '0' || *str <= '9')
      temp += *str;
  }

  if (temp.length()) {
    if (minus) {
      answer -= stoi(temp);
    } else if (plus) {
      answer += stoi(temp);
    }
  }

  return answer;
}