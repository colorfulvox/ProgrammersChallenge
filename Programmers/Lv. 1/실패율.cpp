/*
1. dat에 각 스테이지별 이용자 수를 저장한다.
2. 실패율과 스테이지 번호를 저장하는 class info의 테이블 배열을 생성한다.
(여기서는 1이 첫번째가아닌 0을 첫번째 스테이지로 했다.)
3. 총 이용자수를 users에 저장하고 dat를 순회하면서 스테이지의 실패율을 구한뒤
users를 업데이트 해나간다.
(여기서 분모가 0이거나 분자가 0일경우 실패율을 0으로 저장한다.)
4. compare 함수를 생성해 실패율을 기준으로 내림차순 정렬한다.
(실패율이 같다면 인덱스가 작은 수부터 나오도록 정렬한다.)
*/

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class info {
 public:
  double fail;
  int idx;
  info(double _fail, int _idx) : fail(_fail), idx(_idx) {}
};

bool compare(info a, info b) {
  if (a.fail == b.fail) return a.idx < b.idx;
  return a.fail > b.fail;
}

vector<int> solution(int N, vector<int> stages) {
  vector<int> answer;

  vector<int> dat(N + 1, 0);
  for (int s = 0; s < stages.size(); ++s) {
    dat[stages[s] - 1]++;
  }

  double users = stages.size();
  vector<info> table;
  for (int d = 0; d < N; ++d) {
    if (users == 0 || dat[d] == 0)
      table.push_back(info(0.0f, d));
    else {
      table.push_back(info((double)dat[d] / users, d));
      users -= dat[d];
    }
  }
  sort(table.begin(), table.end(), compare);

  for (int t = 0; t < table.size(); ++t) answer.push_back(table[t].idx + 1);

  return answer;
}