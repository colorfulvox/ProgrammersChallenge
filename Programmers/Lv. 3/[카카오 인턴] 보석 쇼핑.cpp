/*
1. Map에 각 보석들과 각 갯수를 0으로 저장한다.
2. 저장하면서 만약 새로운 보석이 Map에 들어올경우 count를 1씩추가한다.
3. 맨앞에서부터 첫번째 구간을 먼저 구할것이다.
/---반복---/
4. queue에 맨앞에서부터 인덱스와, 보석 이름을 push한다.
5. 선택한 보석의 Map에 갯수가 0일경우 최초로 한개가 등장한것이기에
count를 1 감소한다.
/---반복---/
6. 만약 count가 0이되면 처음으로 찾은 구간이다.
7. 하지만 최적화된 구간이 아니므로 queue front에서부터
pop을 하면서 만약 Pop한 보석이 Map의 카운트를 0으로 만들경우
거기까지가 최적화된 보석구간이기에 answer을 업데이트한다.

8. 첫 구간을 찾았다. 이후 구간도 찾아줘야한다.
(시작 구간은 첫구간을 찾을때의 마지막 idx+1부터이다. (answer[1])
/---반복---/
9. 이번에는 queue front를 pop하고 Map의 보석 갯수를 1 감소 시킨다.
10. 만약 Map 보석 갯수가 0이되면 count를 1 증가시킨다.
(1개이상 보석이 포함되야하기에)
11. 새로운 보석를 Map 보석 갯수에 증가시키기전에
만약 Map 보석 갯수가 0이면 Count를 1 감소시킨다.
12. 보석을 다시 queue에 저장하고 Map도 1증가시킨다.
13. 만약 count가 0이되면 다음 구간을 찾은것이다.
answer를 업데이트하기전에 첫구간때 찾은 것처럼 7번방식으로 최적화를 시킨다.
14. 최적화 시킨 새로운 구간이 첫 구간보다 짧거나 같을때는 s가 작은 것을 고른다.
/---반복---/

*/
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct info {
  int idx;
  string gem;
};

vector<int> solution(vector<string> gems) {
  vector<int> answer(2, 0);

  map<string, int> gemlst;
  int count = 0;

  for (auto gem : gems) {
    if (gemlst.find(gem) == gemlst.end()) {
      ++count;
      gemlst[gem] = 0;
    }
  }
  queue<info> q;

  for (int i = 0; i < gems.size(); ++i) {
    string gem = gems[i];
    if (gemlst[gem] == 0) --count;
    gemlst[gem]++;
    q.push({i, gem});

    if (count == 0) {
      answer[1] = i;
      break;
    }
  }
  while (q.size()) {
    info p = q.front();

    if (gemlst[p.gem] - 1 == 0) {
      answer[0] = p.idx;
      break;
    } else
      gemlst[p.gem]--;
    q.pop();
  }

  for (int i = answer[1] + 1; i < gems.size(); ++i) {
    info p = q.front();
    q.pop();
    gemlst[p.gem]--;
    if (gemlst[p.gem] == 0) ++count;

    string gem = gems[i];
    if (gemlst[gem] == 0) --count;
    gemlst[gem]++;
    q.push({i, gem});

    if (count == 0) {
      int s = q.front().idx;
      int l = i;
      while (q.size()) {
        info pp = q.front();

        if (gemlst[pp.gem] - 1 == 0) {
          s = pp.idx;
          break;
        } else
          gemlst[pp.gem]--;
        q.pop();
      }
      if (l - s < answer[1] - answer[0]) {
        answer[0] = s;
        answer[1] = l;
      } else if (l - s == answer[1] - answer[0]) {
        if (s < answer[0]) {
          answer[0] = s;
          answer[1] = l;
        }
      }
    }
  }

  answer[0]++;
  answer[1]++;
  return answer;
}