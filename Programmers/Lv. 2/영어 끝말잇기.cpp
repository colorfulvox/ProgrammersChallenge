#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<string> words) {
  vector<int> answer;

  map<string, bool> table;

  int round = 0;
  int cur = n + 1;
  bool flag = true;
  string before = "";

  for (int i = 0; i < words.size(); ++i) {
    if (cur > n) {
      round++;
      cur = 1;
    }

    if (before == "") {
      table[words[i]] = true;
      before = words[i];
    } else {
      if (before[before.length() - 1] != words[i][0] ||
          table.find(words[i]) != table.end()) {
        flag = false;
        break;
      } else {
        before = words[i];
        table[words[i]] = true;
      }
    }
    ++cur;
  }

  if (flag) {
    answer.push_back(0);
    answer.push_back(0);
  } else {
    answer.push_back(cur);
    answer.push_back(round);
  }

  return answer;
}