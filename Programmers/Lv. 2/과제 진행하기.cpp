#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

struct Work {
  string sub;
  int start;
  int time;
};

struct Remain {
  string sub;
  int time;
};

bool cmp(Work a, Work b) { return a.start < b.start; }

vector<string> solution(vector<vector<string>> plans) {
  vector<string> answer;

  vector<Work> work;
  stack<Remain> st;
  for (auto pl : plans) {
    string sub = pl[0];
    int start = stoi(pl[1].substr(0, 2)) * 60 + stoi(pl[1].substr(3));
    int time = stoi(pl[2]);

    work.push_back({sub, start, time});
  }

  sort(work.begin(), work.end(), cmp);

  int cur = -1;
  Work curwk;
  for (auto wk : work) {
    if (cur == -1) {
      curwk = wk;
      cur = curwk.start;
    } else {
      if (cur + curwk.time > wk.start) {
        int remain = (curwk.time - (wk.start - cur));
        st.push({curwk.sub, remain});
        cur = wk.start;
        curwk = wk;
      } else {
        answer.push_back(curwk.sub);
        int empty = (wk.start - (cur + curwk.time));

        if (empty) {
          while (st.size()) {
            Remain p = st.top();
            st.pop();

            if (p.time <= empty) {
              answer.push_back(p.sub);
              empty -= p.time;
            } else {
              p.time -= empty;
              st.push(p);
              break;
            }
          }
        }
        cur = wk.start;
        curwk = wk;
      }
    }
  }
  answer.push_back(work.back().sub);

  while (st.size()) {
    Remain p = st.top();
    st.pop();
    answer.push_back(p.sub);
  }

  return answer;
}