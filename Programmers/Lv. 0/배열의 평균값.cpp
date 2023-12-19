#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
  double answer = 0;
  for (auto num = numbers.begin(); num != numbers.end(); num++) {
    answer += *num;
  }
  answer /= numbers.size();
  return answer;
}