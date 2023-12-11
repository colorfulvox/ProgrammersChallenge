#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
  vector<int> answer;
  for (int i = 1; i <= sqrt(n); ++i) {
    if (n % i == 0) {
      if (i != n / i) answer.push_back(n / i);

      answer.push_back(i);
    }
  }
  sort(answer.begin(), answer.end());

  return answer;
}