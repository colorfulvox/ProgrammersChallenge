#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool compare(int a, int b) { return a > b; }

int solution(int k, vector<int> tangerine) {
  int answer = 0;
  vector<int> dat(10000001, 0);

  for (int i = 0; i < tangerine.size(); ++i) {
    dat[tangerine[i]]++;
  }

  sort(dat.begin(), dat.end(), compare);

  for (int i = 0; i < dat.size(); ++i) {
    if (k - dat[i] > 0) {
      k -= dat[i];
      ++answer;
    } else {
      ++answer;
      break;
    }
  }

  return answer;
}