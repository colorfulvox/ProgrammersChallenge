#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> elements) {
  int answer = 0;
  vector<int> table;

  for (int i = 0; i < elements.size(); ++i) {
    table.push_back(elements[i]);

    int sum = 0;
    for (int c = 0; c < elements.size(); ++c) {
      int idx = i + c;
      if (idx >= elements.size()) {
        idx -= elements.size();
      }
      sum += elements[idx];
      table.push_back(sum);
    }
  }
  sort(table.begin(), table.end());
  for (int i = 0; i < table.size(); ++i) {
    if (i != 0 && table[i - 1] != table[i]) {
      ++answer;
    } else if (i == 0)
      ++answer;
  }

  return answer;
}