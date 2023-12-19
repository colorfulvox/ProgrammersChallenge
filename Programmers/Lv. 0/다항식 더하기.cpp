#include <string>
#include <vector>

using namespace std;

string solution(string polynomial) {
  string answer = "";

  string temp = "";
  int x = 0;
  int num = 0;
  for (auto poly = polynomial.begin(); poly < polynomial.end(); ++poly) {
    if (*poly == 'x') {
      if (!temp.length())
        ++x;
      else
        x += stoi(temp);
      temp = "";
    } else if (*poly == ' ') {
      if (temp.length()) {
        num += stoi(temp);
        temp = "";
      }
    } else if (*poly >= '0' && *poly <= '9')
      temp += *poly;
  }
  if (temp.length()) num += stoi(temp);

  if (x > 0 && num > 0) {
    if (x > 1) answer += to_string(x);
    answer += "x + ";
    answer += to_string(num);
  } else if (x > 0) {
    if (x > 1) answer += to_string(x);
    answer += "x";
  } else if (num > 0) {
    answer += to_string(num);
  }

  return answer;
}