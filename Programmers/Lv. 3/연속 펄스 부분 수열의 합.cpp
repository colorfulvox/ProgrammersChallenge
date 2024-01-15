#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> sequence) {
  long long answer = 0;

  vector<int> se1 = vector<int>(sequence.begin(), sequence.end());
  vector<int> se2 = vector<int>(sequence.begin(), sequence.end());

  int one = 1;
  for (int s = 0; s < se1.size(); ++s) {
    se1[s] *= one;
    se2[s] *= -one;

    one = -one;
  }

  vector<long long> dp1 = vector<long long>(se1.size(), 0);
  vector<long long> dp2 = vector<long long>(se1.size(), 0);
  dp1[0] = se1[0];
  dp2[0] = se2[0];
  if (dp1[0] > dp2[0])
    answer = dp1[0];
  else
    answer = dp2[0];

  for (int s = 1; s < se1.size(); ++s) {
    dp1[s] = se1[s];
    dp2[s] = se2[s];

    if (dp1[s] < se1[s] + dp1[s - 1]) dp1[s] = se1[s] + dp1[s - 1];
    if (dp2[s] < se2[s] + dp2[s - 1]) dp2[s] = se2[s] + dp2[s - 1];

    if (dp1[s] > answer) answer = dp1[s];
    if (dp2[s] > answer) answer = dp2[s];
  }

  return answer;
}