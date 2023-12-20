#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct info {
  int num;
  int cnt;
};

bool compare(info a, info b) { return a.cnt > b.cnt; }

vector<int> solution(string s) {
  vector<int> answer;

  // 1. 문자열 배열에 저장
  vector<vector<int>> table;

  string num = "";
  bool flag = false;
  int idx = -1;

  int size = 0;
  for (int i = 1; i < s.length() - 1; ++i) {
    if (s[i] == '{') {
      table.push_back(vector<int>());
      ++idx;
      flag = true;
    } else if (s[i] == ',') {
      if (flag) {
        int n = stoi(num);
        table[idx].push_back(n);
        num = "";
      }
    } else if (s[i] >= '0' && s[i] <= '9')
      num += s[i];

    else if (s[i] == '}') {
      flag = false;
      int n = stoi(num);
      table[idx].push_back(n);
      num = "";
      if (size < table[idx].size()) size = table[idx].size();
    }
  }

  // 많이 나온 숫자를 count
  vector<info> dat(100001);

  for (int t = 0; t < table.size(); ++t) {
    for (int i = 0; i < table[t].size(); ++i) {
      dat[table[t][i]].num = table[t][i];
      dat[table[t][i]].cnt++;
    }
  }

  sort(dat.begin(), dat.end(), compare);

  for (int d = 0; d < dat.size(); ++d) {
    if (dat[d].cnt == 0) break;
    answer.push_back(dat[d].num);
  }

  return answer;
}