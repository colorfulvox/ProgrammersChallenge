#include <map>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string msg) {
  vector<int> answer;

  map<string, int> table;

  for (int i = 'A'; i <= 'Z'; ++i) {
    string temp = "";
    temp += i;
    table[temp] = (i - 'A') + 1;
  }
  int next = table["Z"] + 1;

  string temp = "";
  for (int i = 0; i < msg.length(); ++i) {
    temp = msg[i];

    while (true) {
      if (i + 1 < msg.length()) {
        string tm = temp;
        tm += msg[i + 1];
        if (table.find(tm) != table.end()) {
          temp = tm;
          ++i;
        } else {
          table[tm] = next++;
          break;
        }
      } else
        break;
    }
    answer.push_back(table[temp]);
  }

  return answer;
}