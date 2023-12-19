#include <string>
#include <vector>

using namespace std;

int solution(string s) {
  int answer = 0;

  vector<int> table;

  string temp = "";
  bool minus = false;

  for (int i = 0; i < s.length(); ++i) {
    if (s[i] >= '0' && s[i] <= '9') temp += s[i];

    if (s[i] == 'Z') answer -= table[table.size() - 1];

    if (s[i] == ' ') {
      if (temp.length()) {
        int num;
        if (minus)
          num = stoi(temp) * -1;
        else
          num = stoi(temp);

        table.push_back(num);
        answer += table[table.size() - 1];
        temp = "";
        minus = false;
      }
    }
    if (s[i] == '-') minus = true;
  }
  if (temp.length()) {
    if (minus)
      answer += stoi(temp) * -1;
    else
      answer += stoi(temp);
  }
  return answer;
}