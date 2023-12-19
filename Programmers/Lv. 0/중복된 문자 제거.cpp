#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
  string answer = "";

  vector<bool> used(200, false);

  for (int i = 0; i < my_string.length(); ++i) {
    if (used[my_string[i]]) continue;
    answer += my_string[i];
    used[my_string[i]] = true;
  }

  return answer;
}