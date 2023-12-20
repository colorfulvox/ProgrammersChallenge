/*
1 = 1   1
2 = 2   1 1      2
3 = 3   1 1 1    2 1, 1 2

4 = 5
  [3]         [2]
1 1 1 (1)      1 1 (2)
2 1 (1)         2 (2)
1 2 (1)

5 = 8
   [4]        [3]
1 1 1 1 (1)   1 1 1 (2)
2 1 1 (1)     2 1 (2)
1 2 1 (1)     1 2 (2)
1 1 2 (1)
2 2 (1)
*/
#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
  vector<long long> table(n + 1, 0);
  table[1] = 1;
  table[2] = 2;

  long long answer = 0;

  for (int i = 3; i <= n; ++i) {
    table[i] = (table[i - 1] + table[i - 2]) % 1234567;
  }
  answer = table[n];

  return answer;
}