/*
각 지갑별로 가로 세로 중 세로를 제일 작은 크기로 배치한다.
그리고 지갑중 가로, 세로의 최대 크기를 구한다.
*/

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
  int answer = 0;

  int rmax = -21e8;
  int cmax = -21e8;
  for (int s = 0; s < sizes.size(); ++s) {
    if (sizes[s][0] < sizes[s][1]) {
      int temp = sizes[s][0];
      sizes[s][0] = sizes[s][1];
      sizes[s][1] = temp;
    }

    if (rmax < sizes[s][0]) rmax = sizes[s][0];
    if (cmax < sizes[s][1]) cmax = sizes[s][1];
  }
  answer = rmax * cmax;

  return answer;
}