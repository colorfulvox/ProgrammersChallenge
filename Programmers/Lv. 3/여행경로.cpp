#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;
vector<vector<bool>> maps;  // 각 공항별 경로 map
vector<vector<int>> used;   // 각 공항별 경로 count
vector<int> path;           // 찾은 경로
vector<string> table;       // 정렬된 공항 문자열 리스트
vector<string> answer;
int cnt = 0;  // 티켓 갯수

void dfs(int idx, int level) {
  if (level == cnt) {
    answer.push_back("ICN");
    for (int p = 0; p < path.size(); ++p) answer.push_back(table[path[p]]);
    return;
  }

  for (int c = 1; c < maps.size(); ++c) {
    if (answer.size()) return;
    if (maps[idx][c]) {
      if (used[idx][c] == 0) continue;
      used[idx][c]--;
      path[level] = c;
      dfs(c, level + 1);
      used[idx][c]++;
    }
  }
}

vector<string> solution(vector<vector<string>> tickets) {
  /*
1. 각 공항 문자열을 크기 순서대로 table에 저장한다.
2. 정렬된 문자열 table을 기준으로 hash map에 idx를 저장한다.
(table.push_back("");는 0번째는 안쓰겠다는 뜻이다.)
3. tickets의 각 경로에따라
각 공항별 이동이 가능한 경로를 체크하는 maps와
각 공항별 이동이 가능한 경로의 횟수를 저장하는 used를 만든다.(중복 티켓)
4. 첫번째 경로인 ICN의 인덱스 번호를 시작으로 dfs를 실행한다.
5. 만약 해당 공항(ICN)에서 갈 수 있는 경로가 있을 경우(maps)
해당 경로로 갈 수 있는 횟수가 보장되면(used) 해당 공항으로 이동한다.
6. 5번을 반복하면 결국 level(이동한 횟수)와 cnt가 같아져 path가 최종 경로이다.
*/

  table.push_back("");

  for (auto tick : tickets) {
    string a = tick[0];
    string b = tick[1];

    if (find(table.begin(), table.end(), a) == table.end()) table.push_back(a);
    if (find(table.begin(), table.end(), b) == table.end()) table.push_back(b);
  }

  sort(table.begin() + 1, table.end());
  map<string, int> idxmap;
  for (int t = 1; t < table.size(); ++t) {
    idxmap[table[t]] = t;
  }

  maps = vector<vector<bool>>(table.size(), vector<bool>(table.size(), false));
  used = vector<vector<int>>(table.size(), vector<int>(table.size(), 0));

  for (auto tick : tickets) {
    int i = idxmap[tick[0]];
    int j = idxmap[tick[1]];
    maps[i][j] = true;
    used[i][j]++;
  }
  cnt = tickets.size();
  path = vector<int>(cnt, 0);
  int start = idxmap["ICN"];
  dfs(start, 0);

  return answer;
}