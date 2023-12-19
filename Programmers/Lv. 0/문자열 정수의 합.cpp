#include <string>
#include <vector>

using namespace std;

int solution(string num_str) {
  int answer = 0;

  for (auto num = num_str.begin(); num < num_str.end(); ++num) {
    answer += *num - '0';
  }

  return answer;
}