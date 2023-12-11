#include <string>
#include <vector>

using namespace std;

int solution(string binomial) {
  int answer = 0;

  string a = "";
  string b = "";
  bool flag = true;
  char op;

  for (auto bi = binomial.begin(); bi < binomial.end(); ++bi) {
    if (flag && *bi >= '0' && *bi <= '9')
      a += *bi;
    else if (!flag && *bi >= '0' && *bi <= '9')
      b += *bi;
    else if (*bi != ' ') {
      op = *bi;
      flag = false;
    }
  }

  if (op == '+') answer = stoi(a) + stoi(b);
  if (op == '-') answer = stoi(a) - stoi(b);
  if (op == '*') answer = stoi(a) * stoi(b);

  return answer;
}