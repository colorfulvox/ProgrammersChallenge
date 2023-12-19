#include <string>
#include <vector>

using namespace std;

int solution(string s) {
  int answer = 0;

  char tm;
  int cur = 0;
  int other = 0;

  for (int i = 0; i < s.length(); ++i) {
    if (cur == 0 && other == 0) {
      tm = s[i];
      cur++;
    } else if (tm == s[i])
      ++cur;
    else if (tm != s[i])
      ++other;

    if (cur == other) {
      cur = 0;
      other = 0;
      ++answer;
    }
  }

  if (cur > 0) ++answer;

  return answer;
}