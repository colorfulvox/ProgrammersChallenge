#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string alp) {
  string answer = "";

  for (auto word = my_string.begin(); word < my_string.end(); ++word) {
    if (*word == alp[0])
      answer += *word - 'a' + 'A';
    else
      answer += *word;
  }

  return answer;
}