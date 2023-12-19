#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
  string answer = "";

  for (auto word = myString.begin(); word < myString.end(); ++word) {
    if (*word >= 'a' && *word <= 'z')
      answer += *word - 'a' + 'A';
    else
      answer += *word;
  }

  return answer;
}