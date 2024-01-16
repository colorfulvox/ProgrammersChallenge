#include <string>
#include <vector>

using namespace std;

vector<int> answer(2, 0);

string func(string x) {
  int zero = 0;
  for (auto w : x) {
    if (w == '0') ++zero;
  }
  answer[1] += zero;
  int num = x.length() - zero;

  string temp = "";
  while (num) {
    temp += to_string(num % 2);
    num /= 2;
  }
  return temp;
}

vector<int> solution(string s) {
  while (s.length() != 1) {
    s = func(s);
    ++answer[0];
  }

  return answer;
}