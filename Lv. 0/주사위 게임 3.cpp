// dat에 각 횟수에대한 값을 저장하고
// dat 배열을 탐색하며 저장된 값만 벡터 table에 저장
// table의 갯수에 따라 조건 연산

#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

class info {
 public:
  int idx;
  int cnt;
  info(int _idx, int _cnt) : idx(_idx), cnt(_cnt) {}
};

bool cmp(info a, info b) { return a.cnt > b.cnt; }

int solution(int a, int b, int c, int d) {
  int answer = 21e8;
  vector<info> table;
  int dat[7] = {0};
  dat[a]++;
  dat[b]++;
  dat[c]++;
  dat[d]++;

  for (int i = 1; i < 7; ++i) {
    if (dat[i] != 0) table.push_back(info(i, dat[i]));
  }
  sort(table.begin(), table.end(), cmp);

  if (table.size() == 1) {
    answer = table[0].idx * 1111;
  } else if (table.size() == 2) {
    if (table[0].cnt == table[1].cnt) {
      answer = (table[0].idx + table[1].idx) * abs(table[0].idx - table[1].idx);
    } else {
      answer = (10 * table[0].idx + table[1].idx) *
               (10 * table[0].idx + table[1].idx);
    }
  } else if (table.size() == 3) {
    answer = table[1].idx * table[2].idx;
  } else {
    for (int i = 0; i < table.size(); ++i) {
      if (answer > table[i].idx) answer = table[i].idx;
    }
  }

  return answer;
}