#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
  int answer = -21e8;

  sort(numbers.begin(), numbers.end());

  for (auto num = numbers.begin(); num < numbers.end() - 1; ++num) {
    if (answer < *num * *(num + 1)) answer = *num * *(num + 1);
  }
  return answer;
}