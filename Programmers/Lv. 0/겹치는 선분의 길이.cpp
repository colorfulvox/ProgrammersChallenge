// -100 부터 100 까지 i로 순회하면서
// 각 line 별로 i가 해당 line에 속해있는지 검사한다.
// 그리고 만약 속해있는 line이 두개 이상이면
// 해당 line들은 겹쳐있는 부분이기에 answer를 증가시킨다.

// 여기서 시작 지점만 i가 같거나 크게 잡은 이유는
// 실제로 겹치는 부분을 계산할때 5-3 = 2가 나와야되지만
// 끝 구간까지 같은걸 검사하면 겹치는 부분이 3으로 나와버린다.

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> lines) {
  int answer = 0;

  for (int i = -100; i < 101; ++i) {
    int cnt = 0;

    for (int j = 0; j < lines.size(); ++j) {
      if (lines[j][0] <= i && lines[j][1] > i) ++cnt;
    }
    if (cnt > 1) ++answer;
  }

  return answer;
}