#include <string>
#include <vector>

using namespace std;

int solution(int n) {
  int answer = 0;

  vector<bool> used = vector<bool>(n + 1, false);

  for (int i = 1; i <= n; ++i) {
    if (used[i]) continue;
    if (n % i == 0) {
      if (i != n / i)
        answer += 2;
      else
        answer++;
      used[i] = used[n / i] = true;
    }
  }
  return answer;
}