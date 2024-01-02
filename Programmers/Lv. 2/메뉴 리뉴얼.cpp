#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b) {
  return a.second > b.second;
}

vector<map<string, int>> table(11);

void func(int idx, string tm, string target) {
  if (tm.length() >= 2) {
    table[tm.length()][tm]++;
  }
  if (idx == target.length()) return;

  for (int i = idx; i < target.length(); ++i) {
    func(i + 1, tm + target[i], target);
  }
}

vector<string> solution(vector<string> orders, vector<int> course) {
  vector<string> answer;

  for (int i = 0; i < orders.size(); ++i) {
    sort(orders[i].begin(), orders[i].end());
    func(0, "", orders[i]);
  }

  for (int c = 0; c < course.size(); ++c) {
    if (table[course[c]].size()) {
      vector<pair<string, int>> temp(table[course[c]].begin(),
                                     table[course[c]].end());
      sort(temp.begin(), temp.end(), cmp);

      int num = -1;
      for (auto tb : temp) {
        if (tb.second <= 1) break;
        if (num == -1)
          num = tb.second;
        else if (num != tb.second)
          break;
        answer.push_back(tb.first);
      }
    }
  }
  sort(answer.begin(), answer.end());

  return answer;
}