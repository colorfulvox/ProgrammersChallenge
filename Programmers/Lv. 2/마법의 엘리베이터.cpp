/*
1의 자리가 5일때 두가지를 고려해야한다.
1. 다음 자리 수가 5이상이면 +1 증가 시킨다. (+로 처리)
2. 아닐 경우 넘어간다. (-로 처리)

65 일때는 -> 75 => 8이지만
45 일때는 -> 45 => 9이다.

*/

#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
  int answer = 0;

  while (storey) {
    int dig = storey % 10;
    if (dig >= 5) {
      answer += (10 - dig);
      storey /= 10;
      if (dig == 5 && storey % 10 >= 5)
        ++storey;
      else if (dig != 5)
        ++storey;

    } else {
      answer += dig;
      storey /= 10;
    }
  }

  return answer;
}