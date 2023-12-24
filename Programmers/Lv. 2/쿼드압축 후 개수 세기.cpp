#include <string>
#include <vector>

using namespace std;

vector<int> answer(2, 0);

// 함수 인자에 배열을 넣지말자
// 특히 재귀 함수에 배열 인자를 넣게되면 시간이 더 걸린다.
vector<vector<int>> quad;

void func(int fy, int fx, int ly, int lx) {
  bool flag = true;
  int target = quad[fy][fx];

  // 전체 검사
  for (int r = fy; r < ly; ++r) {
    if (!flag) break;
    for (int c = fx; c < lx; ++c) {
      if (target != quad[r][c]) {
        flag = false;
        break;
      }
    }
  }

  // 전체 검사 결과가 맞을 경우 answer에 값을 추가한다.
  if (flag) {
    answer[target]++;
    return;
  } else {
    // 시간 초과로 2x2일때는 그냥 카운트하고 종료 시킨다.
    if (ly - fy == 2) {
      for (int r = fy; r < ly; ++r) {
        for (int c = fx; c < lx; ++c) {
          answer[quad[r][c]]++;
        }
      }

    }
    // 아닐 경우 4개로 쪼개서 검사한다.
    else {
      func(fy, fx, ly / 2 + fy / 2, lx / 2 + fx / 2);
      func(fy, lx / 2 + fx / 2, ly / 2 + fy / 2, lx);
      func(ly / 2 + fy / 2, fx, ly, lx / 2 + fx / 2);
      func(ly / 2 + fy / 2, lx / 2 + fx / 2, ly, lx);
    }
  }
  return;
}

vector<int> solution(vector<vector<int>> arr) {
  quad = arr;
  int n = arr.size();

  func(0, 0, n, n);

  return answer;
}