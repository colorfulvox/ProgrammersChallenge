#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
  vector<int> answer;

  int start = total;
  int result = 0;
  for (int i = 0; i < num; ++i) {
    result += start;
    --start;
  }

  int end = start + 1;
  start = total;

  while (true) {
    if (result == total) {
      while (end <= start) answer.push_back(end++);
      break;
    } else {
      result -= start--;
      result += --end;
    }
  }

  return answer;
}