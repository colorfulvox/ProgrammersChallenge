#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> quiz) {
  vector<string> answer;

  for (int i = 0; i < quiz.size(); ++i) {
    string temp = quiz[i];

    string a = "";
    bool achk = true;
    string b = "";
    bool bchk = false;
    bool cal = true;
    string result = "";

    for (int t = 0; t < temp.length(); ++t) {
      if ((temp[t] == '-' || temp[t] == '+') && temp[t + 1] == ' ') {
        if (temp[t] == '-') cal = false;

        achk = false;
        bchk = true;
      } else if (temp[t] == '-') {
        if (achk)
          a += '-';
        else if (bchk)
          b += '-';
        else
          result += '-';
      }
      if (temp[t] == '=') bchk = false;

      if (temp[t] >= '0' && temp[t] <= '9') {
        if (achk)
          a += temp[t];
        else if (bchk)
          b += temp[t];
        else
          result += temp[t];
      }
    }

    if (cal) {
      if (stoi(a) + stoi(b) == stoi(result))
        answer.push_back("O");
      else
        answer.push_back("X");
    } else {
      if (stoi(a) - stoi(b) == stoi(result))
        answer.push_back("O");
      else
        answer.push_back("X");
    }
  }

  return answer;
}