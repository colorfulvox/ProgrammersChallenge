#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
  vector<int> answer;

  int day = 1;
  int idx = 0;
  int cnt = 0;

  while (idx < progresses.size()) {
    if (progresses[idx] + (speeds[idx] * day) >= 100) {
      ++cnt;
      ++idx;
    } else {
      if (cnt > 0) {
        answer.push_back(cnt);
        cnt = 0;
      }
      ++day;
    }
  }
  if (cnt != 0) answer.push_back(cnt);

  return answer;
}