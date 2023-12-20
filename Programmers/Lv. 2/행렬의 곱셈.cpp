#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1,
                             vector<vector<int>> arr2) {
  vector<vector<int>> answer(arr1.size(), vector<int>(arr2[0].size(), 0));

  for (int r = 0; r < answer.size(); ++r) {
    for (int c = 0; c < answer[0].size(); ++c) {
      int cnt = 0;

      for (int i = 0; i < arr1[0].size(); ++i) {
        cnt += arr1[r][i] * arr2[i][c];
      }
      answer[r][c] = cnt;
    }
  }

  return answer;
}