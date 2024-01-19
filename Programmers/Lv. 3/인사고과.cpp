#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool cmp(vector<int> a, vector<int> b) {
  if (a[0] == b[0]) return a[1] < b[1];
  return a[0] > b[0];
}

int solution(vector<vector<int>> scores) {
  int answer = 1;

  int left = scores[0][0];
  int right = scores[0][1];

  sort(scores.begin(), scores.end(), cmp);

  // for (auto s : scores) cout << s[0] << " " << s[1] << endl;

  int maxright = 0;

  for (auto s : scores) {
    if (left < s[0] && right < s[1]) return -1;

    if (s[1] >= maxright) {
      if (right + left < s[0] + s[1]) ++answer;
      maxright = s[1];
    }
  }

  return answer;
}