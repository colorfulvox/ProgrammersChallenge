#include <iostream>
#include <string>
#include <vector>
using namespace std;
int solution(string s) {
  int answer = 1;
  int n = s.length();
  vector<vector<bool>> dp(n, vector<bool>(n, false));

  for (int i = 0; i < n; ++i) {
    dp[i][i] = true;
    if (i != 0 && s[i - 1] == s[i]) {
      if (answer < 2) answer = 2;
      dp[i - 1][i] = true;
    }
  }

  for (int i = 2; i < n; ++i) {
    for (int j = 0; i + j < n; ++j) {
      if (s[j] == s[i + j] && dp[j + 1][i + j - 1]) {
        dp[j][i + j] = true;
        if (i + 1 > answer) answer = i + 1;
      }
    }
  }

  // for(int i=0;i<n;++i)
  // {
  //     for(int j=0;j<n;++j)cout<<dp[i][j]<<" ";
  //     cout<<endl;
  // }

  return answer;
}