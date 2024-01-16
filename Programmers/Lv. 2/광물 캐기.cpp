#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct info {
  int d = 0;
  int i = 0;
  int s = 0;
  int w = 0;
};

bool cmp(info a, info b) { return a.w > b.w; }

int solution(vector<int> picks, vector<string> minerals) {
  int answer = 0;

  vector<info> table;

  int limit = picks[0] + picks[1] + picks[2];

  int idx = 0;

  for (int i = 0; i < minerals.size(); i += 5) {
    if (!limit) break;
    vector<string> mine(
        minerals.begin() + i,
        minerals.begin() + (i + 5 > minerals.size() ? minerals.size() : i + 5));
    info tb;
    for (auto m : mine) {
      if (m == "diamond") {
        tb.d += 1;
        tb.i += 5;
        tb.s += 25;
        tb.w += 25;
      }
      if (m == "iron") {
        tb.d += 1;
        tb.i += 1;
        tb.s += 5;
        tb.w += 5;
      }
      if (m == "stone") {
        tb.d += 1;
        tb.i += 1;
        tb.s += 1;
        tb.w += 1;
      }
    }
    --limit;
    table.push_back(tb);
  }

  sort(table.begin(), table.end(), cmp);

  for (auto tb : table) {
    if (picks[0] > 0) {
      answer += tb.d;
      --picks[0];
    } else if (picks[1] > 0) {
      answer += tb.i;
      --picks[1];
    } else if (picks[2] > 0) {
      answer += tb.s;
      --picks[2];
    }
  }

  return answer;
}