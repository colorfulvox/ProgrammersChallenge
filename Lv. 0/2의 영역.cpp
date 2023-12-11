#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
  vector<int> answer;
  int left = 0;
  bool lflag = false;
  int right = arr.size() - 1;
  bool rflag = false;

  while (left <= right) {
    if (arr[left] == 2) {
      lflag = true;
    } else
      left++;
    if (arr[right] == 2) {
      rflag = true;
    } else
      right--;

    if (lflag && rflag) break;
  }
  if (left > right)
    answer.push_back(-1);
  else
    for (; left <= right; ++left) answer.push_back(arr[left]);

  return answer;
}