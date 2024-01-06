#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool cmp1(vector<int> a, vector<int> b) { return a[0] < b[0]; }
bool cmp2(vector<int> a, vector<int> b, int idx) {
  if (a[idx] == b[idx]) return a[0] > b[0];
  return a[idx] < b[idx];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
  int answer = 0;

  vector<vector<int>> table;
  table.push_back(vector<int>(data[0].size(), 0));
  for (auto d : data) {
    table.push_back(vector<int>(d.begin(), d.end()));
  }
  if (col == 1)
    sort(table.begin(), table.end(), cmp1);
  else {
    --col;
    sort(table.begin(), table.end(),
         [col](auto a, auto b) { return cmp2(a, b, col); });
  }

  while (row_begin <= row_end) {
    int idx = row_begin;

    int num = 0;
    for (int d = 0; d < table[0].size(); ++d) {
      num += (table[idx][d] % idx);
    }
    answer = (answer ^ num);

    ++row_begin;
  }

  return answer;
}