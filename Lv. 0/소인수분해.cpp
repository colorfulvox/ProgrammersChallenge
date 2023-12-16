#include <string>
#include <vector>

using namespace std;

// 에라토스테네스의 체 사용

vector<int> solution(int n) {
  vector<int> answer;

  vector<bool> table(n + 1, true);

  for (int i = 2; i < table.size(); ++i) {
    if (!table[i]) continue;

    for (int j = 2; j <= n; ++j) {
      if (i * j <= n) table[i * j] = false;
    }
  }

  for (int i = 2; i < table.size(); ++i) {
    if (n % i == 0 && table[i]) answer.push_back(i);
  }

  return answer;
}