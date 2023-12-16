#include <string>
#include <vector>

using namespace std;

vector<int> solution(int l, int r) {
  vector<int> answer;

  for (int i = l; i <= r; ++i) {
    if (i % 5 == 0) {
      string temp = to_string(i);
      bool flag = true;
      for (auto tm = temp.begin(); tm < temp.end(); ++tm) {
        if (*tm != '0' && *tm != '5') {
          flag = false;
          break;
        }
      }
      if (flag) answer.push_back(i);
    }
  }
  if (!answer.size()) answer.push_back(-1);
  return answer;
}