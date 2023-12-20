#include <string>
#include <vector>

using namespace std;

int MAX = -21e8;

vector<bool> used(9, false);

void func(int energy, int stage, vector<vector<int>> dungeons) {
  if (energy < 0) return;

  if (MAX < stage) MAX = stage;

  for (int d = 0; d < dungeons.size(); ++d) {
    if (used[d]) continue;

    if (dungeons[d][0] <= energy && energy - dungeons[d][1] >= 0) {
      used[d] = true;
      func(energy - dungeons[d][1], stage + 1, dungeons);
      used[d] = false;
    }
  }
}

int solution(int k, vector<vector<int>> dungeons) {
  int answer = -1;

  func(k, 0, dungeons);

  answer = MAX;
  return answer;
}