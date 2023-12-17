#include <algorithm>
#include <string>
#include <vector>

bool compare(int a, int b) { return a > b; }

using namespace std;

int solution(int k, int m, vector<int> score) {
  int answer = 0;

  sort(score.begin(), score.end(), compare);

  int i = 0;

  while (true) {
    if (i + m <= score.size()) {
      vector<int> temp = vector<int>(score.begin() + i, score.begin() + i + m);
      answer += temp[temp.size() - 1] * m;
      i = i + m;
    } else
      break;
  }

  return answer;
}