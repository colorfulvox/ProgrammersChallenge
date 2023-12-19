#include <string>
#include <vector>

using namespace std;

string solution(string s) {
  string answer = "";

  vector<int> cnt(200, 0);

  for (auto st = s.begin(); st < s.end(); ++st) {
    cnt[*st]++;
  }

  for (int i = 'a'; i <= 'z'; ++i) {
    if (cnt[i] == 1) answer += i;
  }

  return answer;
}