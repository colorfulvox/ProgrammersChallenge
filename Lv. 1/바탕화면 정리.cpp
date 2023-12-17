#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
  vector<int> answer;
  int sy = 21e8;
  int sx = 21e8;
  int ey = -21e8;
  int ex = -21e8;

  for (int i = 0; i < wallpaper.size(); ++i) {
    for (int j = 0; j < wallpaper[i].size(); ++j) {
      if (wallpaper[i][j] == '#') {
        if (sy > i) sy = i;
        if (ey < i) ey = i;
        if (sx > j) sx = j;
        if (ex < j) ex = j;
      }
    }
  }
  answer.push_back(sy);
  answer.push_back(sx);
  answer.push_back(ey + 1);
  answer.push_back(ex + 1);
  return answer;
}