/*
n = 3
0,0 0,1 0,2     0 1 2    1번 위치의 index r,c를 알고 싶을때,
1,0 1,1 1,2  :  3 4 5  => r = 1/n, c = 1%n  : r = 0, c = 1
2,0 2,1 2,2     6 7 8

1 2 3
2 2 3  => index r과 c중에 가장 큰수 n을 선택하고 n+1 하면 된다.
3 3 3
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
  vector<int> answer;

  while (left <= right) {
    int r = left / n;
    int c = left % n;

    if (r > c)
      answer.push_back(r + 1);
    else
      answer.push_back(c + 1);
    ++left;
  }

  return answer;
}