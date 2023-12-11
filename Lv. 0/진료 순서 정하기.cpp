/*
table에 원래 위치값, 값 저장
값을 기준으로 table을 sort
table의 0에서부터 원래 위치의 answer에 인덱스에 정렬된 순서 idx 저장
*/

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class info {
 public:
  int level;
  int idx;
  info(int _level, int _idx) : level(_level), idx(_idx) {}
};

bool compare(info a, info b) { return a.level > b.level; }

vector<int> solution(vector<int> emergency) {
  vector<int> answer(emergency.size(), 0);

  vector<info> table;

  for (int i = 0; i < emergency.size(); ++i) {
    table.push_back(info(emergency[i], i));
  }

  sort(table.begin(), table.end(), compare);

  for (int i = 0; i < table.size(); ++i) {
    answer[table[i].idx] = i + 1;
  }

  return answer;
}