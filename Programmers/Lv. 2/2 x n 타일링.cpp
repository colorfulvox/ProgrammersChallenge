/*
그림을 그려보면,

세로 2, 가로 1일때는 1개
세로 2, 가로 2일때는 2개

세로 2, 가로 3일때는 3개
세로 2, 가로 4일때는 5개
세로 2, 가로 5일때는 8개

n = n-1 + n-2로 증가하고 있다.
*/

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
  int answer = 0;

  vector<int> table(n + 1, 0);
  table[1] = 1;
  table[2] = 2;

  for (int i = 3; i <= n; ++i) {
    table[i] = (table[i - 1] + table[i - 2]) % 1000000007;
  }
  answer = table[n];

  return answer;
}