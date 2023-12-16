#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
  vector<int> answer;
  if (arr.size() == 1)
    answer.push_back(-1);
  else {
    int min = 21e8;
    int idx = 0;
    for (int i = 0; i < arr.size(); ++i) {
      if (min > arr[i]) {
        min = arr[i];
        idx = i;
      }
    }
    for (int i = 0; i < arr.size(); ++i) {
      if (i == idx)
        continue;
      else
        answer.push_back(arr[i]);
    }
  }

  return answer;
}