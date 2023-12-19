#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
  vector<int> answer;

  vector<bool> used(100001, false);

  for (int i = 0; i < arr.size(); ++i) {
    if (k == answer.size()) break;

    if (used[arr[i]])
      continue;
    else {
      used[arr[i]] = true;
      answer.push_back(arr[i]);
    }
  }
  for (int i = answer.size(); i < k; ++i) answer.push_back(-1);

  return answer;
}