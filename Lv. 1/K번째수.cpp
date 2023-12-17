#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
  vector<int> answer;

  for (int c = 0; c < commands.size(); ++c) {
    int s = commands[c][0] - 1;
    int e = commands[c][1] - 1;
    int k = commands[c][2];

    vector<int> table = vector<int>(array.begin() + s, array.begin() + e + 1);
    sort(table.begin(), table.end());
    answer.push_back(table[k - 1]);
  }

  return answer;
}