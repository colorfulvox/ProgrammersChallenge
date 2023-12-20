/*
[9, 1, 5, 3, 6, 2] => [-1, 5, 6, 6, -1, -1] 일때,

0. answer의 초기값을 모두 -1로 설정한다.
1. [9, 1, 5, 3, 6, 2] 각 번호별  인덱스, 번호를 저장하는 구조체를 생성한다.
2. priority_queue에 저장한다. (오름차순으로 정렬한다.)
3. 이제 numbers를 순회한다.

(1) pq [9 ]
(2) pq [1 9]
(3) pq [1 9]
저장될 수는 5이며 pq의 top이 1이다.
그래서 1의 뒷큰 수는 5가 된다.
pq에서 info 구조체로 저장된 1를 p에 저장하고 제외시칸다.
info p = [index : 1, num : 1]
pq.pop()

p와 5를 answer에 적용한다.
answer[p.index] = 5

pq에 5보다 작은 수가 있는지 계속 반복한다.
여기서는 9만 남았기에 중단하고 5를 pq에 저장한다.
pq [5 9]
*/
#include <queue>
#include <string>
#include <vector>
using namespace std;
struct info {
  int idx;
  int num;
};

struct cmp {
  bool operator()(info a, info b) { return a.num > b.num; }
};

vector<int> solution(vector<int> numbers) {
  vector<int> answer(numbers.size(), -1);

  priority_queue<info, vector<info>, cmp> pq;

  for (int i = 0; i < numbers.size(); ++i) {
    int num = numbers[i];

    if (pq.size() > 0) {
      while (true) {
        info p = pq.top();
        if (pq.size() > 0 && p.num < num) {
          answer[pq.top().idx] = num;
          pq.pop();
        } else
          break;
      }
    }

    pq.push({i, numbers[i]});
  }

  return answer;
}