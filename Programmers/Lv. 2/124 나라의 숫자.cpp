/*

     1 2  3  4   5   6  7   8    9   10
124  1 2  4  11  12 14  21  22   24  41
3    1 2 10  11  12 20  21  22  100  101

여기서 중요한점은
3의 배수로 나누어 떨어질때이다.

10 -> 4 로 만들어야되는데
3으로 나누면서 0으로 나누어 떨어질경우 4를 추가하고
현재 나누는 수를 -1를 해줘야한다.

예시)
n = 10

10%3 = 1 -> answer += 1, n = 10/3
3%3  = 0 -> answer += 4, n = 3/3 - 1 ... n = 0
answer = 14
reverse --- answer = 41




*/

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(int n) {
  string answer = "";

  while (n) {
    int num = n % 3;

    if (num == 0) {
      answer += '4';
      n /= 3;
      --n;

    } else {
      answer += (num + '0');
      n /= 3;
    }
  }

  reverse(answer.begin(), answer.end());

  return answer;
}