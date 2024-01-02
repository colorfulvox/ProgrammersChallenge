#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct info {
  int idx;
  int cnt;
};

struct cmp {
  bool operator()(info a, info b) {
    if (a.cnt == b.cnt)
      return a.idx > b.idx;
    else
      return a.cnt < b.cnt;
  }
};

bool compare(pair<string, int> a, pair<string, int> b) {
  return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
  vector<int> answer;

  map<string, int> lst;
  map<string, priority_queue<info, vector<info>, cmp>> genlst;

  for (int i = 0; i < genres.size(); ++i) {
    lst[genres[i]] += plays[i];
    genlst[genres[i]].push({i, plays[i]});
  }

  vector<pair<string, int>> sortlst(lst.begin(), lst.end());

  sort(sortlst.begin(), sortlst.end(), compare);

  for (auto st : sortlst) {
    string target = st.first;

    for (int c = 0; c < 2; ++c) {
      if (genlst[target].size() == 0) break;

      info p = genlst[target].top();
      genlst[target].pop();
      answer.push_back(p.idx);
    }
  }

  return answer;
}