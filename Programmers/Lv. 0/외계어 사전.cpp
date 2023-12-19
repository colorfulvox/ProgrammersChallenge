#include <string>
#include <vector>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {
  int answer = 2;
  vector<bool> used(200, false);
  for (auto sp = spell.begin(); sp < spell.end(); ++sp) {
    string temp = *sp;
    used[temp[0]] = true;
  }

  for (int i = 0; i < dic.size(); ++i) {
    vector<bool> us = used;
    bool flag = true;
    if (dic[i].length() != spell.size()) continue;
    for (auto di = dic[i].begin(); di < dic[i].end(); ++di) {
      if (!us[*di]) {
        flag = false;
        break;
      } else
        us[*di] = false;
    }
    if (flag) {
      answer = 1;
      break;
    }
  }

  return answer;
}