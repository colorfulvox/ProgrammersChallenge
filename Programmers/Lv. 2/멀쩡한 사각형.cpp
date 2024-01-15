/*
W,H가 같다면 (W*H) - W 가 답이다.
다를 경우 W,H의 최대공약수 N을 찾는다.
W*H - (N*((W/N + H/N) -1)) 가 답이다.

최대공약수를 구하는 이유
12 x 8에서 몇개가 제외되는지 세보면

먼저 3 x 2 = 4개가 제외된다.

12 x 8 의 최대공약수는 4
12/4 = 3
8/4 = 2

3 X 2 는 4개이기때문에
최대공약수 4와 3X2의 갯수 4개를 곱해
12 X 8의 제외된 갯수는 16이 나온다.

여기서 3 x 2 와같이 두 수의 최대공약수가 1이면 W + H -1이
제외된 갯수이다.
*/

using namespace std;

long long GCD(long long a, long long b) {
  if (a < b) {
    long long tm = a;
    a = b;
    b = tm;
  }
  long long temp;
  while (a % b != 0) {
    temp = a % b;
    a = b;
    b = temp;
  }
  return b;
}

long long solution(int w, int h) {
  long long answer = 1;

  long long W = w;
  long long H = h;
  if (W == H)
    answer = W * H - W;
  else {
    long long N = GCD(W, H);
    answer = W * H - (N * ((W / N + H / N) - 1));
  }

  return answer;
}