#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

bool compare(int a, int b) { return a > b; }

vector<int> solution(vector<int> numlist, int n) {
  vector<int> answer;

  vector<vector<int>> table(10001);

  for (auto num = numlist.begin(); num < numlist.end(); ++num) {
    int idx = abs(*num - n);
    table[idx].push_back(*num);
  }
  for (int i = 0; i < table.size(); ++i) {
    if (table[i].size() > 0) {
      sort(table[i].begin(), table[i].end(), compare);
      for (int t = 0; t < table[i].size(); ++t) answer.push_back(table[i][t]);
    }
  }

  return answer;
}