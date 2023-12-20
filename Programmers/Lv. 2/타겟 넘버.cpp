#include <string>
#include <vector>

using namespace std;
int answer = 0;

void func(int level, int sum, int target, vector<int> numbers) {
  if (level == numbers.size()) {
    if (sum == target) ++answer;
    return;
  }

  func(level + 1, sum + numbers[level], target, numbers);
  func(level + 1, sum - numbers[level], target, numbers);
}

int solution(vector<int> numbers, int target) {
  func(0, 0, target, numbers);

  return answer;
}