#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<bool> flag) {
  vector<int> answer;

  for (int i = 0; i < flag.size(); ++i) {
    if (flag[i]) {
      for (int c = 0; c < arr[i] * 2; ++c) answer.push_back(arr[i]);
    } else {
      for (int c = 0; c < arr[i]; ++c) answer.pop_back();
    }
  }

  return answer;
}