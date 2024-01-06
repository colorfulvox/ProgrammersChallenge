// 프로그래머스 Lv2 배달 문제가 예시이다.

// 다익스트라 : DP를 활용한 최단 경로 탐색 알고리즘
// 특정 노드에서 모든 노드로 가는 최단 경로를 탐색한다.

// 기본 원리
// 1. 출발 노드를 설정한다.
// 2. 출발 노드를 기준으로 각 노드의 최소 비용을 저장한다.
// 3. 방문하지 않은 노드 중 가장 비용이 적은 노드를 선택한다.
// 4. 선택한 노드를 거쳐 특정 노드로 가는 비용과
// 현재 DP에 저장된 비용과 비교한뒤 업데이트 한다.
// 5. 3~4번을 반복한다.

// 선형 방식 : O(N^2)
// 만약 정점의 갯수가 많고 간선이 적을 경우 비효율적이다.
#include <iostream>
#include <vector>
using namespace std;
int solution(int N, vector<vector<int>> road, int K) {
  int answer = 0;

  vector<vector<int>> map(N + 1, vector<int>(N + 1, 21e8));

  for (auto r : road) {
    if (map[r[0]][r[1]] > r[2]) map[r[0]][r[1]] = map[r[1]][r[0]] = r[2];
  }

  vector<bool> used(N + 1, false);
  vector<int> dist(N + 1, 21e8);

  for (int i = 1; i < N + 1; ++i) dist[i] = map[1][i];

  dist[1] = 0;
  used[1] = true;

  for (int i = 1; i < N + 1; ++i) {
    int min = 21e8;
    int idx = 0;

    for (int d = 1; d < N + 1; ++d) {
      if (dist[d] < min && !used[d]) {
        min = dist[d];
        idx = d;
      }
    }

    used[idx] = true;
    for (int j = 1; j < N + 1; ++j) {
      if (!used[j]) {
        if (dist[idx] + map[idx][j] < dist[j]) {
          dist[j] = dist[idx] + map[idx][j];
        }
      }
    }
  }

  for (int i = 1; i < N + 1; ++i)
    if (dist[i] <= K) ++answer;

  return answer;
}

// 인접 리스트방식 : O(N * log N)
// 정점이 많을 경우 효율적이다.
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int solution(int N, vector<vector<int>> road, int K) {
  int answer = 0;

  vector<vector<pair<int, int>>> map(N + 1);

  for (auto r : road) {
    map[r[0]].push_back(make_pair(r[1], r[2]));
    map[r[1]].push_back(make_pair(r[0], r[2]));
  }

  vector<int> dist(N + 1, 21e8);
  dist[1] = 0;

  priority_queue<pair<int, int>> pq;
  pq.push(make_pair(1, 0));

  while (pq.size()) {
    int cur = pq.top().first;

    int distance = -pq.top().second;

    pq.pop();

    if (dist[cur] < distance) continue;
    for (int d = 0; d < map[cur].size(); ++d) {
      int next = map[cur][d].first;

      int nextdist = distance + map[cur][d].second;

      if (nextdist < dist[next]) {
        dist[next] = nextdist;
        pq.push(make_pair(next, -nextdist));
      }
    }
  }

  for (int d = 1; d < N + 1; ++d) {
    if (dist[d] <= K) ++answer;
  }
  return answer;
}