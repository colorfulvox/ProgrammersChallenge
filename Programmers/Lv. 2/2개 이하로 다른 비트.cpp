/*

문제는 어떤 수 N과 비트 차이가 1~2차이나는 N보다 큰 최솟값이다.

N이 (11)1011일때 최솟값은 13(1101) 이며,
맨뒤의 자리에서 처음 0이 나오는 위치에서 01 을 10으로 바꿔주면 답이다.

즉, 1(01)1 => 1(10)1

3 : (01)1 => 5 : (10)1
7 : (01)11 => 11 : (10)11

그래서 처음 0이 등장하기 이전의 비트에서 2(10)를 더해주면 된다.

7 : 0 1 1 1
    3 2 1 0
0의 위치는 3이다. 그리고 0의 이전 위치는 2이다.
그래서 (4)100를 더해주면 된다.
0111 + 0100 => (11)1011

결론적으로 N을 2로 나누면서 나머지가 처음으로 0이 등장할때의 위치 idx에서
pow(2,idx-1)을 더해주면된다.

7 + pow(2,2) = 11

*/
#include <cmath>
#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
  vector<long long> answer;

  for (int i = 0; i < numbers.size(); ++i) {
    long long num = numbers[i];

    int cnt = 0;
    long long tm = num;
    while (tm % 2 == 1) {
      ++cnt;
      tm /= 2;
    }
    if (cnt == 0) cnt = 1;
    answer.push_back(num + pow(2, cnt - 1));
  }
  return answer;
}