/*
n = 15일때
1. 15 % 1 == 0 :  15
2. (15-1)% 2 == 0  : 7 + 8(7+1)
3. (15 -1 -2) % 3 == 0 : 4 + 5(4+1) + 6(4+2)
즉, 4 + 4 + 4 = 12니까 만약 3으로 나누어 떨어지면
4 + 5(4+1) + 6(4+2)가 성립한다.

4. (15 -1 -2 -3) % 4 != 0
5. (15 -1 -2 -3 -4) % 5 != 0 : 1 + 2(1 + 1) + 3(1+ 2) + 4(1 + 3) + 5(1 + 4)
6. (15 -1 -2 -3 -4 -5) % 6 : 종료
*/

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
  int answer = 0;

  int num = 1;

  while (n >= num) {
    if (n % num == 0) ++answer;
    n -= num;
    ++num;
  }

  return answer;
}