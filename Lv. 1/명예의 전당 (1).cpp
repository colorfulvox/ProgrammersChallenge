#include <queue>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int k, vector<int> score) {
  vector<int> answer;

  priority_queue<int> pq;

  for (int i = 0; i < score.size(); ++i) {
    if (i <= (k - 1)) {
      pq.push(score[i] * -1);
    } else {
      if (score[i] > (pq.top() * -1)) {
        pq.pop();
        pq.push(score[i] * -1);
      }
    }

    answer.push_back(pq.top() * -1);
  }

  return answer;
}