#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2,
                vector<string> goal) {
  string answer = "Yes";

  int c1 = 0;
  int c2 = 0;

  for (int g = 0; g < goal.size(); ++g) {
    if (c1 < cards1.size()) {
      if (cards1[c1] == goal[g]) {
        ++c1;
        continue;
      }
    }
    if (c2 < cards2.size()) {
      if (cards2[c2] == goal[g]) {
        ++c2;
        continue;
      }
    }
    answer = "No";
    break;
  }

  return answer;
}