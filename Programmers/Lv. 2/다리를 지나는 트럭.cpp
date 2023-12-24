/*
[7,4,5,6] 이고
다리 길이와 무게가 2, 10일때
2개만 저장가능한 다리 queue를 생성한다.

    bri
1초 [7]  [4,5,6]
2초 [7,0] [4,5,6]
7+4는 무게를 초과하기에 빈 무게인 0을 넣는다.
그리고 아직 7이 지나가는 중이기에
(bri queue의 갯수가 다리 길이(2)와 같을때 지나간걸로 판단한다.)

3초 [0,4] [5,6]
4초 [4,5] [6]
5초 [5,0] [6]
6초 [0,6] []
7초 [6,0] []

8초 [0]
더이상 담을 수 있는 무게도 없고 모든 트럭이 지나갔기에 여기서 종료한다.
*/

#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
  int answer = 0;

  queue<int> bri;
  int len = bridge_length;

  int time = 0;
  int w = 0;

  int t = 0;

  int cnt = 0;
  while (true) {
    if (t == truck_weights.size() && cnt == 0) break;

    if (bri.size() == len) {
      if (bri.front()) --cnt;

      w -= bri.front();
      bri.pop();
    }

    if (t < truck_weights.size() && w + truck_weights[t] <= weight) {
      bri.push(truck_weights[t]);
      w += truck_weights[t];
      ++cnt;
      ++t;
    } else
      bri.push(0);

    ++time;
  }

  answer = time;

  return answer;
}