#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
  vector<int> answer;
  vector<bool> used(10001, false);

  for (int i = 0; i < numbers.size(); ++i) {
    for (int j = i + 1; j < numbers.size(); ++j) {
      used[numbers[i] + numbers[j]] = true;
    }
  }

  for (int i = 0; i < used.size(); ++i) {
    if (used[i]) answer.push_back(i);
  }

  return answer;
}