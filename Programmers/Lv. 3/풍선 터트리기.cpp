// 양끝단은 무조건 남을 수 밖에 없다.
// (그말인 즉슨 양끝단들의 다음 수는 그 이전 값보다 작다면 무조건 남는다는
// 소리다.)

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
  int answer = 0;

  int l = 0;
  int r = a.size() - 1;

  int left = a[l];
  int right = a[r];
  while (left != right) {
    if (left > right) {
      int before = left;
      ++l;
      left = a[l];
      if (right == left) break;
      if (left < before)
        ++answer;
      else
        left = before;
    } else {
      int before = right;
      --r;
      right = a[r];
      if (right == left) break;
      if (right < before)
        ++answer;
      else
        right = before;
    }
    // cout<<left<<" "<<right<<endl;
  }
  answer += 2;

  return answer;
}