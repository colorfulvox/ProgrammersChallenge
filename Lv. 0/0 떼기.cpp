#include <string>
#include <vector>

using namespace std;

string solution(string n_str) {
  string answer = "";

  bool flag = true;
  for (auto word = n_str.begin(); word < n_str.end(); ++word) {
    if (*word == '0' && flag)
      continue;
    else {
      answer += *word;
      flag = false;
    }
  }
  return answer;
}