#include <string>
#include <vector>

using namespace std;

int direct[2][2] = {1, 0, 1, 1};

int solution(vector<vector<int>> triangle) {
  int answer = 0;

  vector<vector<int>> dat(triangle.size(), vector<int>(triangle.size(), 0));
  dat[0][0] = triangle[0][0];

  for (int r = 0; r < triangle.size() - 1; ++r) {
    for (int c = 0; c < triangle[r].size(); ++c) {
      for (int d = 0; d < 2; ++d) {
        int dy = direct[d][0] + r;
        int dx = direct[d][1] + c;

        if (dat[r][c] + triangle[dy][dx] >= dat[dy][dx])
          dat[dy][dx] = dat[r][c] + triangle[dy][dx];

        if (dy == triangle.size() - 1) {
          if (answer < dat[dy][dx]) answer = dat[dy][dx];
        }
      }
    }
  }

  return answer;
}