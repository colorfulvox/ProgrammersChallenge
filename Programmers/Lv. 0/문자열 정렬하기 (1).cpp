#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string my_string) {
  vector<int> answer;

  for (auto word = my_string.begin(); word < my_string.end(); ++word) {
    if (*word >= '0' && *word <= '9') answer.push_back(*word - '0');
  }

  sort(answer.begin(), answer.end());

  return answer;
}