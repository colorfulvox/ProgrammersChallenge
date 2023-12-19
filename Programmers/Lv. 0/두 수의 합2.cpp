#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(string a, string b) {
  string answer = "";

  if (a.length() > b.length()) {
    string temp = a;
    a = b;
    b = temp;
  }
  int dig = 0;
  int al = a.length() - 1;
  int bl = b.length() - 1;

  while (al >= 0) {
    answer += (dig + (a[al] - '0') + (b[bl] - '0')) % 10 + '0';

    if (dig + (a[al] - '0') + (b[bl] - '0') > 9)
      dig = 1;
    else
      dig = 0;

    --al;
    --bl;
  }
  while (bl >= 0) {
    answer += (dig + (b[bl] - '0')) % 10 + '0';
    if (dig + (b[bl] - '0') > 9)
      dig = 1;
    else
      dig = 0;
    --bl;
  }
  if (dig) answer += '1';

  reverse(answer.begin(), answer.end());

  return answer;
}