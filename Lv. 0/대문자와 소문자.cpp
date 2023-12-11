#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
  string answer = "";

  for (auto word = my_string.begin(); word != my_string.end(); ++word) {
    if (*word >= 'A' && *word <= 'Z')
      answer += *word - 'A' + 'a';
    else
      answer += *word - 'a' + 'A';
  }

  return answer;
}