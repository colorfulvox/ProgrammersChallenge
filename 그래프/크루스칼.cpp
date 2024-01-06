// 프로그래머스 LV3 섬 연결하기 문제가 예시이다.

// Kruskal Algorithm : 가장 적은 비용으로 모든 노드를 연결하기 위한 알고리즘
// 최소 비용 신장 트리를 만들기 위한 대표적인 알고리즘

// 최소 비용 신장 트리
// 모든 노드를 연결하면서 사이클이 없고 간선의 가중치 합이 최소인 트리

// 크루스칼의 핵심은 모든 노드간의 간선 정보를 오름차순으로 정렬하는것이다.
// 그리고 비용이 적은 간선부터 그래프에 포함시킬때 사이클이 발생하는지 확인한다.
// 사이클이 발생하면 간선을 포함하지 않는다.
// 사이클은 Union-find로 판단한다.

// 크루스칼 알고리즘은 간선의 수가 적은 경우 유용하다.

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> parent;

bool compare(vector<int> a, vector<int> b) { return a[2] < b[2]; }

int getParent(int n) {
  if (parent[n] == n) return n;
  return parent[n] = getParent(parent[n]);
}

void unionParent(int a, int b) {
  a = getParent(a);
  b = getParent(b);

  if (a < b)
    parent[b] = a;
  else
    parent[a] = b;
}

bool checkParent(int a, int b) {
  a = getParent(a);
  b = getParent(b);
  if (a == b) return true;
  return false;
}

int solution(int n, vector<vector<int>> costs) {
  int answer = 0;

  // 간선 정보를 오름차순으로 정렬
  sort(costs.begin(), costs.end(), compare);

  // union 정보 초기화
  parent = vector<int>(n);
  for (int i = 0; i < n; ++i) parent[i] = i;

  // 최소 비용 신장트리 초기화 (결과를 보기위한 용도)
  vector<vector<int>> map(n, vector<int>(n, 0));

  // 그래프 연결
  for (auto cost : costs) {
    int a = cost[0];
    int b = cost[1];
    int ct = cost[2];

    // 사이클 여부 확인
    if (checkParent(a, b)) continue;
    // 이미 a와 b가 연결되어 있다면 현재 간선을 추가하면 사이클이 발생한다.
    // 그래서 무시한다.

    map[a][b] = map[b][a] = ct;
    unionParent(a, b);  // union 업데이트
    answer += ct;
  }

  // for(int i=0;i<n;++i)
  // {
  //     for(int j=0;j<n;++j)cout<<map[i][j]<<" ";
  //     cout<<endl;
  // }

  return answer;
}