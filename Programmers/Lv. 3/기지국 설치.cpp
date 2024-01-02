#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w) {
  int answer = 0;

  int cur = 1;
  int idx = 0;
  int curs = stations[idx] - w;
  int cure = stations[idx] + w;
  while (cur <= n) {
    if (cur >= curs && cur <= cure) {
      cur = cure + 1;
      if (idx + 1 < stations.size()) {
        idx++;
        curs = stations[idx] - w;
        cure = stations[idx] + w;
      }
    } else {
      ++answer;
      cur = (cur + w * 2) + 1;
    }
  }

  return answer;
}