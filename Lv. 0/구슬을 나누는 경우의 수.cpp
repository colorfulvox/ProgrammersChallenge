/*
n!/(n-m)! * m!

해당 공식을 이용해야되지만, n과 m의 최대 크기가 30이여서
이대로 연산시 long long 타입으로 해도 오버플로우가 발생한다. (표현을 못함)
그래서 생각한 방법은 어차피 연산할때 n/m 으로 1~n/ 1~m 까지의 연산은 약분되서
생략된다. 그래서 m(share)의 연산은 bool table로 체크해 연산을 생략한다. 그럼
n!/(n-m)!만 연산하면 된다. (여기서 n!은 m을 생략한 구간) 추가적으로 answer
타입이 long long 이기에 먼저 answer에 n! 값을 추가하고 (n-m)!을 나눠준다.
*/

#include <string>
#include <vector>

using namespace std;

long long solution(int balls, int share) {
  long long answer = 1;
  vector<bool> table(31, true);

  for (int i = 1; i <= share; ++i) table[i] = false;

  int bshare = balls - share;
  int bsi = 1;

  for (int i = 1; i <= balls; ++i) {
    if (table[i]) {
      if (bsi <= bshare) {
        answer *= i;
        answer /= bsi;
        ++bsi;
      } else
        answer *= i;
    }
  }

  return answer;
}