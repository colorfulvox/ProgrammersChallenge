#include <string>
#include <vector>

using namespace std;

int solution(int n) {
  int answer = 0;

  vector<int> table(100001, 0);
  table[0] = 0;
  table[1] = 1;

  for (int i = 2; i <= n; ++i) {
    table[i] = (table[i - 1] + table[i - 2]) % 1234567;
  }
  answer = table[n];

  return answer;
}