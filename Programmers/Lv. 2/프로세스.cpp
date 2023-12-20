#include <deque>
#include <string>
#include <vector>

using namespace std;

struct info {
  int idx;
  int num;
};

int solution(vector<int> priorities, int location) {
  int answer = 0;

  deque<info> dq;
  vector<int> dat(9, 0);

  for (int i = 0; i < priorities.size(); ++i) {
    dq.push_back({i, priorities[i]});
    dat[priorities[i]]++;
  }

  for (int d = 9; d >= 0;) {
    if (dat[d] == 0) --d;

    while (dat[d] > 0) {
      if (dq.front().num == d) {
        if (dq.front().idx == location) return answer + 1;
        dq.pop_front();
        ++answer;
        dat[d]--;
        break;
      } else {
        info temp = dq.front();
        dq.pop_front();
        dq.push_back(temp);
      }
    }
  }
}