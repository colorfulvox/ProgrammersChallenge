#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<string>> places) {
  vector<int> answer;

  for (auto pl : places) {
    vector<pair<int, int>> p;
    for (int r = 0; r < pl.size(); ++r) {
      for (int c = 0; c < pl.size(); ++c) {
        if (pl[r][c] == 'P') p.push_back(make_pair(r, c));
      }
    }
    if (p.size() == 0)
      answer.push_back(1);
    else {
      bool flag = true;
      for (int i = 0; i < p.size(); ++i) {
        if (!flag) break;
        int ar = p[i].first;
        int ac = p[i].second;
        for (int j = i + 1; j < p.size(); ++j) {
          if (!flag) break;

          int br = p[j].first;
          int bc = p[j].second;

          int dist = abs(ar - br) + abs(ac - bc);
          if (dist > 2) continue;

          if (dist == 2) {
            if (ar == br) {
              if (pl[ar][ac + 1] != 'X') flag = false;
            } else if (ac == bc) {
              if (pl[ar + 1][ac] != 'X') flag = false;
            } else {
              if (ar + 1 == br && ac + 1 == bc) {
                if (pl[ar + 1][ac] != 'X' || pl[ar][ac + 1] != 'X')
                  flag = false;
              } else {
                if (pl[ar + 1][ac] != 'X' || pl[ar][ac - 1] != 'X')
                  flag = false;
              }
            }
          } else
            flag = false;
        }
      }
      if (flag)
        answer.push_back(1);
      else
        answer.push_back(0);
    }
  }

  return answer;
}