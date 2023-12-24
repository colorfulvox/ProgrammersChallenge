#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
  int answer = 0;

  queue<int> q1;
  queue<int> q2;

  long long sum1 = 0;
  long long sum2 = 0;

  for (int i = 0; i < queue1.size(); ++i) {
    q1.push(queue1[i]);
    q2.push(queue2[i]);

    sum1 += queue1[i];
    sum2 += queue2[i];
  }

  int count = q1.size() * 2 + 2;
  // 2를 추가하는 이유
  // a [1, 1, 1, 1]
  // b [2, 2, 2, 2]
  // a를 모두 뺄때 4번
  // (하지만 모두 빼면 a가 0이되니까 b에서 1개를 가져와야됨) 4번 +1
  // b를 모두 뺄때 4번
  // (하지만 모두 빼면 b가 0이되니까 a에서 1개를 가져와야됨) 4번 +1

  while (count--) {
    if (sum1 == sum2) break;

    if (sum1 > sum2) {
      int n = q1.front();
      sum1 -= n;
      sum2 += n;

      q1.pop();
      q2.push(n);
    } else {
      int n = q2.front();
      sum2 -= n;
      sum1 += n;

      q2.pop();
      q1.push(n);
    }
    ++answer;
  }
  if (sum1 != sum2) answer = -1;
  return answer;
}