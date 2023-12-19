#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> arr) {
  int answer = 1;
  bool flag = true;
  for (int i = 0; i < arr.size(); ++i) {
    for (int j = i; j < arr[i].size(); ++j) {
      if (arr[i][j] != arr[j][i]) flag = false;
    }
  }
  if (!flag) answer = 0;

  return answer;
}