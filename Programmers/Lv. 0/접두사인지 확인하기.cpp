#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_prefix) {
  int answer = 0;

  string temp = "";
  for (auto word = my_string.begin(); word < my_string.end(); ++word) {
    temp += *word;

    if (temp == is_prefix) answer = 1;
  }

  return answer;
}