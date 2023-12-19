#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string solution(string X, string Y) {
  string answer = "";

  int xdat[10] = {0};
  int ydat[10] = {0};

  for (auto x = X.begin(); x < X.end(); ++x) xdat[*x - '0']++;
  for (auto y = Y.begin(); y < Y.end(); ++y) ydat[*y - '0']++;

  int dig = 1;
  bool flag = false;
  bool zeroflag = true;
  for (int i = 0; i < 10; ++i) {
    if (xdat[i] != 0 && ydat[i] != 0) {
      int cnt;
      if (xdat[i] > ydat[i])
        cnt = ydat[i];
      else
        cnt = xdat[i];

      flag = true;
      while (cnt--) answer += i + '0';
      if (i != 0) zeroflag = false;
    }
  }

  if (!flag)
    answer = "-1";
  else if (zeroflag)
    answer = "0";
  else
    reverse(answer.begin(), answer.end());

  return answer;
}