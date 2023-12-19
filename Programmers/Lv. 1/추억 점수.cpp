#include <map>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning,
                     vector<vector<string>> photo) {
  vector<int> answer;

  map<string, int> table;
  for (int i = 0; i < name.size(); ++i) {
    table[name[i]] = yearning[i];
  }

  for (int p = 0; p < photo.size(); ++p) {
    answer.push_back(0);
    for (auto str = photo[p].begin(); str < photo[p].end(); ++str) {
      if (table.find(*str) != table.end()) {
        answer[p] += table[*str];
      }
    }
  }

  return answer;
}