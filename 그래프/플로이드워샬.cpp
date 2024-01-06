// 프로그래머스 Lv2 배달 문제가 예시이다.

// 플로이드 워샬 : 모든 정점에서 모든 정점으로의 최단 경로
// 다익스트라처럼 특정 노드에서의 최단 경로가 아닌
// 모든 노드의 최단 경로를 구할때 유용하다.

// 거쳐가는 정점을 기준으로 최단 거리를 구한다.

// 예를들어 노드가 4개일때

// [2->3]으로 가는 최소 비용을 구할때
// [2,3] VS [2 -> 1 -> 3] or [2 -> 4 -> 3]을 비교하여
// 실제 2->3으로 가는 최소 비용을 구한다.

// 1을 거쳐갈 경우의 수
// [2 -> 1 -> 3] , [2 -> 1 -> 4],
// [3 -> 1 -> 2], [3 -> 1 -> 4],
// [4 -> 1 -> 2], [4 -> 1 -> 3]

// 그래서 공식을 정리하면
// [2 -> 3]으로 가는 경로는
// 결국 [x,y] VS [x가 1로 가는 경로] + [1에서 y로 가는 경로]
// 그렇기에 다익스트라보다 비용이 많이 든다.
// 노드 갯수가 N이면 O(N^3)

#include <iostream>
#include <vector>
using namespace std;

int solution(int N, vector<vector<int>> road, int K) {
  int answer = 0;
  vector<vector<int>> map(N + 1, vector<int>(N + 1, 1000000));
  for (auto ro : road) {
    if (map[ro[0]][ro[1]] > ro[2]) {
      map[ro[0]][ro[1]] = ro[2];
      map[ro[1]][ro[0]] = ro[2];
    }
  }

  for (int k = 1; k < N + 1; ++k) {
    for (int i = 1; i < N + 1; ++i) {
      for (int j = 1; j < N + 1; ++j) {
        if (i == j) map[i][j] = 0;  // [1,1] 같은 경로는 0으로 만든다.

        if (map[i][j] > map[i][k] + map[k][j])
          map[i][j] = map[i][k] + map[k][j];
      }
    }
  }
  // for (int i = 1; i < N + 1; ++i)
  //{
  //     for (int j = 1; j < N + 1; ++j)cout << map[i][j] << " ";
  //     cout << endl;
  // }
  for (int i = 1; i < N + 1; ++i) {
    if (map[1][i] <= K) ++answer;
  }

  return answer;
}