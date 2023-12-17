#include <string>
#include <vector>

using namespace std;

int solution(int n) {
  int answer = 0;

  vector<bool> pri(1000001, false);

  for (int i = 2; i <= n; ++i) {
    if (pri[i]) continue;
    ++answer;  // 어차피 소수가 아닌 수들은 continue에서 걸러진다.
               // 그래서 여기서 ++answer를 해도된다.
    for (int j = 2; j <= n; ++j) {
      if (i * j > n) break;
      pri[i * j] = true;
    }
  }

  return answer;
}