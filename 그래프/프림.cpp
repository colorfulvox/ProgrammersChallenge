// 프로그래머스 LV3 섬 연결하기 문제가 예시이다.

// Prim Algorithm : 가장 적은 비용으로 모든 노드를 연결하기 위한 알고리즘
// 최소 비용 신장 트리를 만들기 위한 대표적인 알고리즘

// 최소 비용 신장 트리
// 모든 노드를 연결하면서 사이클이 없고 간선의 가중치 합이 최소인 트리

// 프림 알고리즘의 핵심은 임의의 시작 노드를 선택한뒤
// 선택된 노드와 연결된 간선중 최소 가중치를 가진 간선을 선택하는 것이다.

// 1. 임의의 시작 노드를 선택한다.
// 2. 선택된 노드와 연결된 간선 중 최소 비용을 가진 간선을 선택한다.
// 3. 선택된 간선으로 연결된 노드를 추가한다.
// 4. 모든 노드가 연결될때까지 2~3을 반복한다.

// 프림 알고리즘은 간선의 수가 많을 경우 효율적이다.

#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
  int answer = 0;

  vector<vector<pair<int, int>>> map(n);

  for (auto cs : costs) {
    map[cs[0]].push_back(make_pair(cs[1], cs[2]));
    map[cs[1]].push_back(make_pair(cs[0], cs[2]));
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  // queue에 간선 비용을 오름차순으로 정렬한다.

  vector<bool> used(n, false);

  pq.push(make_pair(0, 0));  // 1. 임의의 시작 노드를 선택한다.

  while (pq.size()) {
    int cur = pq.top().second;
    int cost = pq.top().first;

    pq.pop();

    if (used[cur]) continue;

    used[cur] = true;
    answer += cost;
    // 3. 선택된 간선으로 연결된 노드를 추가한다.
    // 오름차순으로 정렬된 pq에서 노드간의 최소 비용만을 선택하면서
    // 이미 방문한 노드는 무시한다.

    for (auto edge : map[cur]) {
      int next = edge.first;
      int nextcost = edge.second;

      pq.push(make_pair(nextcost, next));
      // 2. 선택된 노드와 연결된 간선 중 최소 비용을 가진 간선을 선택한다.
      // pq는 오름차순으로 정렬된다.
    }
  }

  return answer;
}