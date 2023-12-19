#include <string>
#include <vector>

using namespace std;

vector<int> solution(string my_string) {
  vector<int> answer(52, 0);

  for (auto str = my_string.begin(); str < my_string.end(); ++str) {
    if (*str >= 'a' && *str <= 'z')
      answer[*str - 'a' + 26]++;
    else
      answer[*str - 'A']++;
  }

  return answer;
}