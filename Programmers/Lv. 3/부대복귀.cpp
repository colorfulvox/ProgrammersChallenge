#include <queue>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources,
                     int destination) {
  vector<int> answer;

  vector<vector<pair<int, int>>> map(n + 1);

  for (auto ro : roads) {
    map[ro[0]].push_back(make_pair(ro[1], 1));
    map[ro[1]].push_back(make_pair(ro[0], 1));
  }

  int des = destination;

  vector<int> dist(n + 1, 21e8);
  dist[des] = 0;

  priority_queue<pair<int, int>> pq;
  pq.push(make_pair(des, 0));

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

  for (auto s : sources) {
    if (dist[s] == 21e8)
      answer.push_back(-1);
    else
      answer.push_back(dist[s]);
  }

  return answer;
}