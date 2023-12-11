#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
  vector<vector<int>> answer(num_list.size() / n, vector<int>(n, 0));

  int idx = 0;
  for (int r = 0; r < answer.size(); ++r) {
    for (int c = 0; c < answer[r].size(); ++c) {
      answer[r][c] = num_list[idx++];
    }
  }

  return answer;
}