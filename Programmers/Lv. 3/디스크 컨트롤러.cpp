/*
1. 시작 시간을 오름차순 기준으로 힙(pq)에 정렬한다.
2. 첫번째 시작 시간을 cur에 저장한다.
3. pq의 사이즈가 0일때까지 반복한다.
  (1). 실행시간을 오름차순으로 하는 힙(dq)을 생성한다.
  (2). pq top의 시작 시간이 cur보다 작거나 같은 경우 dq에 계속 저장한다.
  (3). dq의 top 하나를 answer에 적용한다.
       answer += 실행시간 + (cur - 시작시간):대기시간
  (4). cur을 업데이트한다. cur = cur + 실행시간
  만약, dq에 값이 없을 경우 (현재 시간보다 더 높은 시간이 실행시간이다.)
  pq의 top 하나를 answer에 적용한다.
      answer += 실행시간
      cur = 시작시간 + 실행시간
  (5) dq 사이즈가 0이 아니면 pq에 다시 dq를 저장한다.

예시) [[0, 3], [1, 9], [2, 6]]

1. pq = [[0, 3], [1, 9], [2, 6]]
2. cur = 0;

3. (1) dq = [], cur = 0
   (2) pq.top -> [0,3] : dq = [[0,3]] -> pq.pop()
       pq.top -> [1,9] : X
   (3) dq.top -> [0,3] -> dq.pop()
       answer += 3 + (0 - 0) : 3
   (4) cur = 0 + 3
   (5) dq.size() == 0
   -----------------------------------------------

   (1) dq = [], cur = 3
   (2) pq.top -> [1,9] : dq = [[1,9]] -> pq.pop()
       pq.top -> [2,6] : dq = [[2,6], [1,9]] -> pq.pop()
       pq.size()가 0이기에 중단
   (3) dq.top -> [2,6] -> dq.pop()
       answer += 6 + (3 - 2) : 7
   (4) cur = 6 + 3
   (5) dq.top -> [1,9] -> pq.push([1,9]) -> dq.pop()
   -----------------------------------------------

   (1) dq = [], cur = 9
   (2) pq.top -> [1,9] : dq = [[1,9]] -> pq.pop()
       pq.size()가 0이기에 중단
   (3) dq.top -> [1,9] -> dq.pop()
       answer += 9 + (9 - 1) : 17
   (4) cur = 9 + 9
   (5) dq.size() == 0
   -----------------------------------------------
   pq 사이즈가 0이기에 종료

answer = (3 + 7 + 17)/3
*/

#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct dat {
  int start;
  int exec;
};

struct cmp {
  bool operator()(dat a, dat b) { return a.start > b.start; }
};

struct cmp2 {
  bool operator()(dat a, dat b) { return a.exec > b.exec; }
};

int solution(vector<vector<int>> jobs) {
  int answer = 0;

  priority_queue<dat, vector<dat>, cmp> pq;

  for (auto jb : jobs) {
    pq.push({jb[0], jb[1]});
  }
  int cur = pq.top().start;
  while (pq.size()) {
    priority_queue<dat, vector<dat>, cmp2> dq;

    while (pq.size() && pq.top().start <= cur) {
      dq.push(pq.top());
      pq.pop();
    }

    if (dq.size()) {
      dat d = dq.top();
      dq.pop();
      answer += d.exec + (cur - d.start);
      cur = d.exec + cur;
    } else {
      dat d = pq.top();
      pq.pop();
      answer += d.exec;
      cur = d.exec + d.start;
    }
    while (dq.size()) {
      pq.push(dq.top());
      dq.pop();
    }
  }

  return answer / jobs.size();
}