#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
  string answer = "";

  for (auto word = myString.begin(); word < myString.end(); ++word) {
    if (*word < 'l')
      answer += 'l';
    else
      answer += *word;
  }

  return answer;
}