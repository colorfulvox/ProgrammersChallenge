#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numLog) {
  string answer = "";

  int log = numLog[0];

  for (int i = 1; i < numLog.size(); ++i) {
    if (log + 1 == numLog[i]) answer += 'w';
    if (log - 1 == numLog[i]) answer += 's';
    if (log + 10 == numLog[i]) answer += 'd';
    if (log - 10 == numLog[i]) answer += 'a';
    log = numLog[i];
  }

  return answer;
}