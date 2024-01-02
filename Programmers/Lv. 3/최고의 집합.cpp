/*
곱이 최대인 수는 결국 S를 N으로 나눈 집합들이다.

N=2, S=8

[4,4]

N=3, S=9
[3,3,3]

그리고 만약에 나머지가 존재할경우 나머지를 카운트로
맨뒤자리부터 1씩 추가하면 된다.

N=5, S=9

[1,1,1,1,1] 나머지는 4이기에 뒷자리부터 1를 증가
: [1,2,2,2,2]

=> [1,1,1,1,5] 이것보다 [1,2,2,2,2] 이게 더 크다.

*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
  vector<int> answer;

  int num = s / n;
  if (n > s)
    answer.push_back(-1);
  else {
    for (int i = 0; i < n; ++i) answer.push_back(num);

    int idx = answer.size() - 1;
    int cnt = s % n;
    while (cnt--) {
      answer[idx]++;
      --idx;
    }
  }
  return answer;
}