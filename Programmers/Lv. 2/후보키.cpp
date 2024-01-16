#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int limit = 0;
int path[8] = {0};
bool used[8] = {false};

struct dat {
  int size;
  vector<int> com;
};

struct cmp {
  bool operator()(dat a, dat b) { return a.size > b.size; }
};

priority_queue<dat, vector<dat>, cmp> pq;

void func(int idx, int level) {
  if (level == limit) {
    return;
  }

  for (int i = idx; i < limit; ++i) {
    path[level] = i;
    vector<int> temp;
    for (int p = 0; p < level + 1; ++p) {
      temp.push_back(path[p]);
    }
    pq.push({level + 1, temp});
    func(i + 1, level + 1);
  }
}

int solution(vector<vector<string>> relation) {
  int answer = 0;

  limit = relation[0].size();

  func(0, 0);

  vector<vector<int>> fk;

  while (pq.size()) {
    dat p = pq.top();
    pq.pop();
    // 최소성 조사
    bool check = true;

    for (int f = 0; f < fk.size(); ++f) {
      int fkcnt = 0;
      for (int k = 0; k < fk[f].size(); ++k) {
        int num = fk[f][k];
        for (int i = 0; i < p.size; ++i) {
          if (num == p.com[i]) ++fkcnt;
        }
      }

      if (fk[f].size() == fkcnt) {
        check = false;
        break;
      }
    }
    if (!check) continue;

    map<string, bool> mp;
    // 유일성 조사

    bool flag = true;
    for (int r = 0; r < relation.size(); ++r) {
      string temp = "";
      for (int i = 0; i < p.size; ++i) {
        temp += relation[r][p.com[i]];
      }
      if (mp.find(temp) == mp.end())
        mp[temp] = true;
      else {
        flag = false;
        break;
      }
    }
    if (flag) {
      fk.push_back(p.com);
      // for(int i=0;i<p.size;++i)cout<<p.com[i]<<" ";
      cout << endl;
      ++answer;
    }
  }

  return answer;
}