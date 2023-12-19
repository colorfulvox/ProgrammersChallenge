#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct info {
  int count;
  int value;
};

bool compare(info a, info b) { return a.value > b.value; }

int main(int argc, char** argv) {
  int w, n;
  cin >> w >> n;

  int val = 0;

  vector<info> table;

  for (int i = 0; i < n; ++i) {
    int count, value;
    cin >> count >> value;
    table.push_back({count, value});
  }

  sort(table.begin(), table.end(), compare);
  int idx = 0;

  while (w > 0) {
    if (w - table[idx].count < 0) {
      val += (table[idx].value * w);
      w = 0;
    } else {
      val += (table[idx].value * table[idx].count);
      w -= table[idx].count;
      ++idx;
    }
  }
  cout << val;
  return 0;
}