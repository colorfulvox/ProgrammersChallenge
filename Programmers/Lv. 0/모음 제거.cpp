#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
  string answer = "";
  for (auto word = my_string.begin(); word != my_string.end(); ++word) {
    if (*word != 'a' && *word != 'e' && *word != 'i' && *word != 'o' &&
        *word != 'u')
      answer += *word;
  }
  return answer;
}