#include <deque>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> stones, int k) {
  int answer = 200000001;

  // sliding Window + deque 방식
  deque<pair<int, int>> dq;

  for (int s = 0; s < stones.size(); ++s) {
    while (dq.size() > 0 && dq.front().first < s - k + 1) dq.pop_front();
    while (dq.size() > 0 && dq.back().second < stones[s]) dq.pop_back();

    dq.push_back({s, stones[s]});

    while (dq.size() > k) dq.pop_front();

    if (s >= k - 1 && answer > dq.front().second) answer = dq.front().second;
  }

  // 이분 탐색 방식
  int left = 1;
  int right = 200000000;

  while (left < right) {
    int mid = (left + right) / 2;
    int cnt = 0;
    for (auto st : stones) {
      if (mid - st >= 0)
        ++cnt;
      else
        cnt = 0;
      if (cnt == k) {
        answer = mid;
        break;
      }
    }

    if (cnt >= k)
      right = mid;
    else
      left = mid + 1;
  }

  return answer;
}