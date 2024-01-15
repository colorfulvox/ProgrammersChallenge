#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
  int answer = 21e8;
  if (s.length() == 1) return 1;
  for (int len = 1; len <= s.length() / 2; ++len) {
    string temp = "";
    string area = "";

    int cnt = 0;
    string num = "";
    for (int i = 0;; i += len) {
      if (area == "") {
        area = s.substr(i, len);
        temp += area;
      } else {
        if (i + len > s.length()) {
          temp += s.substr(i, len);
          break;
        }

        if (area != s.substr(i, len)) {
          area = s.substr(i, len);
          temp += area;
          if (cnt > 0) {
            ++cnt;
            num += to_string(cnt);
            cnt = 0;
          }
        } else
          ++cnt;
      }
    }
    if (cnt > 0) {
      ++cnt;
      num += to_string(cnt);
    }
    if (answer > num.length() + temp.length())
      answer = num.length() + temp.length();
  }
  return answer;
}