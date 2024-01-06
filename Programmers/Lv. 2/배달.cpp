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
