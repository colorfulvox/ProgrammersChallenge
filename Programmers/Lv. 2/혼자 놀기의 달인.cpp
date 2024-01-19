#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int solution(vector<int> cards) {
  int answer = 0;

  int n = cards.size() + 1;

  vector<int> table(n, 0);

  int idx = 1;
  for (auto ca : cards) {
    table[idx++] = ca;
  }

  vector<bool> used(n, false);

  vector<int> box;

  for (int i = 1; i < n; ++i) {
    if (used[i]) continue;
    int cnt = 1;

    used[i] = true;
    queue<int> q;
    q.push(table[i]);

    while (q.size()) {
      int p = q.front();
      q.pop();

      if (used[p]) continue;
      used[p] = true;
      ++cnt;
      p = table[p];
      q.push(p);
    }
    box.push_back(cnt);
  }
  // for(auto b : box)cout<<b<<" ";
  sort(box.begin(), box.end(), greater<int>());
  if (box.size() > 1) answer = box[0] * box[1];
  return answer;
}