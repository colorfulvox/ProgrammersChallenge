#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_string) {
  vector<string> answer;

  while (my_string.length()) {
    answer.push_back(my_string);
    my_string = my_string.substr(1);
  }

  sort(answer.begin(), answer.end());

  return answer;
}