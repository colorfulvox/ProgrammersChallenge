#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<string, vector<string>> banlst;

vector<vector<string>> table;

vector<string> lst;
vector<bool> used;
void func(int level, int idx, vector<string> banid) {
  if (level == banid.size()) {
    bool flag = true;
    for (auto ta : table) {
      int cnt = 0;
      for (int t = 0; t < ta.size(); ++t) {
        for (int s = 0; s < lst.size(); ++s) {
          if (ta[t] == lst[s]) {
            ++cnt;
            break;
          }
        }
      }
      if (cnt == lst.size()) {
        flag = false;
        break;
      }
    }
    if (flag) {
      table.push_back(lst);
    }

    return;
  }

  for (int t = idx; t < banid.size(); ++t) {
    if (used[t]) continue;
    used[t] = true;
    string tar = banid[t];
    for (auto ban : banlst[tar]) {
      bool flag = true;
      for (auto ls : lst) {
        if (ban == ls) {
          flag = false;
          break;
        }
      }
      if (flag) {
        lst[level] = ban;
        func(level + 1, idx + 1, banid);
        lst[level] = "";
      }
    }
    used[t] = false;
  }
}

int solution(vector<string> user_id, vector<string> banned_id) {
  int answer = 0;

  lst = vector<string>(banned_id.size(), "");
  used = vector<bool>(banned_id.size(), false);
  for (auto ban : banned_id) {
    for (auto user : user_id) {
      bool flag = true;
      if (user.length() == ban.length()) {
        for (int i = 0; i < user.length(); ++i) {
          if (ban[i] == '*') continue;
          if (ban[i] != user[i]) {
            flag = false;
            break;
          }
        }

      } else
        flag = false;
      if (flag) {
        if (banlst.find(ban) != banlst.end()) {
          bool check = true;
          for (auto bn : banlst[ban]) {
            if (bn == user) {
              check = false;
              break;
            }
          }
          if (check) banlst[ban].push_back(user);
        } else
          banlst[ban].push_back(user);
      }
    }
  }

  func(0, 0, banned_id);

  //     for(auto ta : table)
  //     {

  //         for(auto t : ta)cout<<t<<" ";
  //         cout<<"\n";
  //     }
  //     cout<<"\n";
  answer = table.size();

  return answer;
}