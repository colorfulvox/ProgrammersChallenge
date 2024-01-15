#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
  int answer = 0;

  priority_queue<int> pq;

  for (auto e : enemy) {
    if (pq.size() != k) {
      ++answer;
      pq.push(-e);
    } else {
      int temp;
      if (-pq.top() < e) {
        temp = -pq.top();
        pq.pop();
        pq.push(-e);
      } else
        temp = e;

      if (n < temp) break;
      n -= temp;
      ++answer;
    }
  }

  return answer;
}