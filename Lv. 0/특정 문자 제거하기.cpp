#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string letter) {
  string answer = "";
  for (auto word = my_string.begin(); word != my_string.end(); ++word) {
    if (*word != letter[0]) answer += *word;
  }
  return answer;
}