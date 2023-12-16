#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
한정된 예산으로 가장 많은 부서에게 지원을 해줘야한다.
그래서 d를 오름차순으로 정렬한뒤 적은 예산의 부서 부터 지원하면서
예산비용이 음수가 되면 지원을 멈추면된다.
*/

int solution(vector<int> d, int budget) {
  int answer = 0;

  sort(d.begin(), d.end());

  for (int i = 0; i < d.size(); ++i) {
    if (budget - d[i] < 0) break;
    budget -= d[i];
    ++answer;
  }
  return answer;
}