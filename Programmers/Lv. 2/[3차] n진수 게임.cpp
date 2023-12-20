#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string func(int n, int num) {
  string temp = "";
  while (num) {
    if (num % n >= 10)
      temp += ('A' + (num % n) - 10);
    else
      temp += (num % n + '0');

    num /= n;
  }
  reverse(temp.begin(), temp.end());
  if (temp.length() == 0) temp = "0";

  return temp;
}

string solution(int n, int t, int m, int p) {
  string answer = "";
  int num = 0;

  int midx = 1;

  while (true) {
    string str = func(n, num);
    for (int s = 0; s < str.length(); ++s) {
      if (midx == p) {
        answer += str[s];
        --t;
        if (t == 0) return answer;
      }
      ++midx;
      if (midx > m) midx = 1;
    }
    ++num;
  }
}