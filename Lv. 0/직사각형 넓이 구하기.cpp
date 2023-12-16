#include <cmath>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> dots) {
  int answer = 0;

  int maxx = -21e8, minx = 21e8;
  int maxy = -21e8, miny = 21e8;
  for (int i = 0; i < dots.size(); ++i) {
    if (dots[i][0] > maxx) maxx = dots[i][0];
    if (dots[i][0] < minx) minx = dots[i][0];
    if (dots[i][1] > maxy) maxy = dots[i][1];
    if (dots[i][1] < miny) miny = dots[i][1];
  }

  answer = (maxx - minx) * (maxy - miny);

  return answer;
}