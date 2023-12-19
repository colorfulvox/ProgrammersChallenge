#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
  vector<int> answer;

  if (n > m) {
    int tm = n;
    n = m;
    m = tm;
  }
  int num = 0;
  for (int i = 1; i <= n; ++i) {
    if (n % i == 0 && m % i == 0) num = i;
  }
  answer.push_back(num);

  int j = m;
  while (true) {
    if (j % n == 0 && j % m == 0) {
      num = j;
      break;
    }
    ++j;
  }
  answer.push_back(j);

  return answer;
}