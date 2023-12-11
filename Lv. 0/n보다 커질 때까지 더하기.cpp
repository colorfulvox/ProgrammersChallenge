#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int n) {
  int answer = 0;
  for (auto num = numbers.begin(); num < numbers.end(); ++num) {
    if (answer > n) break;
    answer += *num;
  }
  return answer;
}