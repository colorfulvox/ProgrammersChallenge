#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
  vector<int> answer;

  for (int i = 0; i < queries.size(); ++i) {
    int s = queries[i][0];
    int e = queries[i][1];
    int k = queries[i][2];

    int ans = -1;
    for (; s <= e; ++s) {
      if (k < arr[s]) {
        if (ans == -1)
          ans = arr[s];
        else {
          if (ans > arr[s]) ans = arr[s];
        }
      }
    }
    answer.push_back(ans);
  }

  return answer;
}