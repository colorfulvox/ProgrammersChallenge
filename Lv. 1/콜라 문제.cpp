// (n/a) * b : 받을 수 있는 콜라 수 == 콜라병 수
// (n%a) : (받을 수 있는 콜라 수에서) 제외된 콜라병 수
// 그래서 n을 업데이트 할때
// (n / a) * b + (n % a) 으로 받은 콜라 병수 + 제외된 콜라병 수로 계산
#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
  int answer = 0;

  while (n >= a) {
    answer += (n / a) * b;
    n = (n / a) * b + (n % a);
  }

  return answer;
}