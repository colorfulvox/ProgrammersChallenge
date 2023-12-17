/*
1. 각 키패드 번호 위치값을 저장한다.
2. left와 right의 처음 위치값을 저장한다.
3. numbers를 순회하며 1,4,7은 L , 3,6,9는 R로 저장하고
각 위치값을 POS배열을 통해 업데이트 한다. (ly,lx , ry,rx)
나머지 2,5,8,0은 L과 R 각각의 거리 값을 구한뒤 비교하여 업데이트 한다.
*/

#include <cmath>
#include <string>
#include <vector>

using namespace std;

class pos {
 public:
  int y;
  int x;
  pos(int _y, int _x) : y(_y), x(_x) {}
};

string solution(vector<int> numbers, string hand) {
  string answer = "";

  vector<pos> POS;

  int r = 0;
  int c = 0;
  POS.push_back(pos(3, 1));
  for (int i = 1; i <= 9; ++i) {
    POS.push_back(pos(r, c));
    ++c;
    if (c == 3) {
      c = 0;
      r++;
    }
  }

  int ly = 3;
  int lx = 0;

  int ry = 3;
  int rx = 2;

  for (int i = 0; i < numbers.size(); ++i) {
    int idx = numbers[i];
    if (idx == 1 || idx == 4 || idx == 7) {
      answer += 'L';
      ly = POS[idx].y;
      lx = POS[idx].x;
    } else if (idx == 3 || idx == 6 || idx == 9) {
      answer += 'R';
      ry = POS[idx].y;
      rx = POS[idx].x;
    } else {
      int Lloc = abs(POS[idx].y - ly) + abs(POS[idx].x - lx);
      int Rloc = abs(POS[idx].y - ry) + abs(POS[idx].x - rx);

      if (Lloc < Rloc) {
        answer += 'L';
        ly = POS[idx].y;
        lx = POS[idx].x;
      } else if (Lloc > Rloc) {
        answer += 'R';
        ry = POS[idx].y;
        rx = POS[idx].x;
      } else if (Lloc == Rloc) {
        if (hand == "left") {
          answer += 'L';
          ly = POS[idx].y;
          lx = POS[idx].x;
        } else {
          answer += 'R';
          ry = POS[idx].y;
          rx = POS[idx].x;
        }
      }
    }
  }

  return answer;
}