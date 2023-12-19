#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(string myString) {
  vector<string> answer;

  string temp = "";
  for (auto word = myString.begin(); word < myString.end(); ++word) {
    if (*word == 'x') {
      if (temp.length() > 0) answer.push_back(temp);
      temp = "";
    } else
      temp += *word;
  }

  if (temp.length() > 0) answer.push_back(temp);

  sort(answer.begin(), answer.end());

  return answer;
}