#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> map;

int func(int s_y, int s_x, int e_y, int e_x) {
  vector<int> table;

  for (int c = s_x; c <= e_x; ++c) table.push_back(map[s_y][c]);
  for (int r = s_y + 1; r <= e_y; ++r) table.push_back(map[r][e_x]);
  for (int c = e_x - 1; c >= s_x; --c) table.push_back(map[e_y][c]);
  for (int r = e_y - 1; r >= s_y + 1; --r) table.push_back(map[r][s_x]);

  int min = *min_element(table.begin(), table.end());

  int last = table.back();
  for (int t = table.size() - 1; t > 0; --t) table[t] = table[t - 1];
  table[0] = last;

  int idx = 0;

  for (int c = s_x; c <= e_x; ++c) map[s_y][c] = table[idx++];
  for (int r = s_y + 1; r <= e_y; ++r) map[r][e_x] = table[idx++];
  for (int c = e_x - 1; c >= s_x; --c) map[e_y][c] = table[idx++];
  for (int r = e_y - 1; r >= s_y + 1; --r) map[r][s_x] = table[idx++];

  return min;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
  vector<int> answer;

  map = vector<vector<int>>(rows, vector<int>(columns, 0));
  int num = 1;
  for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < columns; ++c) map[r][c] = num++;
  }

  for (auto q : queries) {
    answer.push_back(func(q[0] - 1, q[1] - 1, q[2] - 1, q[3] - 1));
  }

  return answer;
}