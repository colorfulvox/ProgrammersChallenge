#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
  string answer = "";

  for (auto word = my_string.begin(); word < my_string.end(); ++word) {
    if (*word >= 'A' && *word <= 'Z') *word = *word - 'A' + 'a';
  }

  sort(my_string.begin(), my_string.end());
  answer = my_string;

  return answer;
}