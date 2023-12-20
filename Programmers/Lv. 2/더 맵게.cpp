#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> scoville, int K) {
  int answer = 0;

  priority_queue<int, vector<int>, greater<int>> pq;

  for (int s = 0; s < scoville.size(); ++s) pq.push(scoville[s]);

  while (true) {
    if (pq.top() >= K) break;

    if (pq.size() == 1) {
      answer = -1;
      break;
    }

    int a1 = pq.top();
    pq.pop();
    int a2 = pq.top();
    pq.pop();

    pq.push(a1 + a2 * 2);
    ++answer;
  }

  return answer;
}