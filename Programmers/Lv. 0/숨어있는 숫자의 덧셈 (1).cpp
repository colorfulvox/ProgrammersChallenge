#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
  int answer = 0;

  for (auto word = my_string.begin(); word != my_string.end(); ++word) {
    if (*word >= '0' && *word <= '9') answer += *word - '0';
  }
  return answer;
}