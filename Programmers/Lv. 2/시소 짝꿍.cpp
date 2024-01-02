#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> weights) {
  long long answer = 0;

  vector<int> ssang(4001, 0);
  vector<int> dat(1001, 0);

  for (auto w : weights) {
    answer += dat[w];
    dat[w]++;

    int d = dat[w];

    ssang[w * 2]++;
    ssang[w * 3]++;
    ssang[w * 4]++;

    answer += (ssang[w * 2] - d);
    answer += (ssang[w * 3] - d);
    answer += (ssang[w * 4] - d);
  }

  return answer;
}