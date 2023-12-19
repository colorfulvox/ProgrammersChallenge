#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
  string answer = "";

  vector<bool> table(200, false);

  for (auto sk = skip.begin(); sk < skip.end(); ++sk) table[*sk] = true;

  for (int i = 0; i < s.length(); ++i) {
    char tm = s[i];
    for (int t = 0; t < index;) {
      if (tm + 1 > 'z')
        tm = 'a';
      else
        tm++;

      if (table[tm]) {
        continue;
      }

      ++t;
    }
    answer += tm;
  }

  return answer;
}