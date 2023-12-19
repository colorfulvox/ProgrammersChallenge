#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int n) {
  string answer = "";
  for (auto word = my_string.begin(); word != my_string.end(); ++word) {
    for (int i = 0; i < n; ++i) answer += *word;
  }
  return answer;
}