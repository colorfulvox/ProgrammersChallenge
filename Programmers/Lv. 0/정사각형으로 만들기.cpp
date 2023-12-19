#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) {
  vector<vector<int>> answer;

  if (arr.size() > arr[0].size()) {
    answer = vector<vector<int>>(arr.size(), vector<int>(arr.size(), 0));

  } else {
    answer = vector<vector<int>>(arr[0].size(), vector<int>(arr[0].size(), 0));
  }

  for (int r = 0; r < answer.size(); ++r) {
    for (int c = 0; c < answer[r].size(); ++c) {
      if (r >= arr.size() || c >= arr[0].size())
        answer[r][c] = 0;
      else
        answer[r][c] = arr[r][c];
    }
  }
  return answer;
}