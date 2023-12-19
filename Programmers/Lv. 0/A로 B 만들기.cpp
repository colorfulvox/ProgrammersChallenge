#include <string>
#include <vector>

using namespace std;

int solution(string before, string after) {
  int answer = 1;

  vector<int> count(200, 0);

  for (auto be = before.begin(); be < before.end(); ++be) {
    count[*be]++;
  }

  for (auto af = after.begin(); af < after.end(); ++af) {
    count[*af]--;
  }

  for (int i = 'a'; i <= 'z'; ++i) {
    if (count[i] != 0) answer = 0;
  }

  return answer;
}