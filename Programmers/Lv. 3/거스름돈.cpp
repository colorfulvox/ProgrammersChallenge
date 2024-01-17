#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> money) {
  int answer = 0;

  vector<int> dp(n + 1, 0);
  dp[0] = 1;

  for (auto mon : money) {
    for (int d = mon; d <= n; ++d) {
      dp[d] = dp[d] + dp[d - mon];
    }
    // for(auto d : dp)cout<<d<<" ";
    // cout<<endl;
  }
  answer = dp[n];

  return answer;
}