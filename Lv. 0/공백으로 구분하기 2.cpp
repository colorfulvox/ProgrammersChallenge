#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_string) {
  vector<string> answer;

  string temp = "";
  for (auto word = my_string.begin(); word < my_string.end(); ++word) {
    if (*word == ' ') {
      if (temp.length() > 0) answer.push_back(temp);
      temp = "";
    } else
      temp += *word;
  }

  if (temp.length() > 0) answer.push_back(temp);

  return answer;
}