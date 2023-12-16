#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
  int answer = 0;

  int pl = p.length();

  for (int i = 0; i <= t.length() - pl; ++i) {
    string temp = t.substr(i, pl);
    if (temp <= p) ++answer;
  }

  return answer;
}