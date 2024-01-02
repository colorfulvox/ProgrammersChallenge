/*
N이 3일때 경우의 수
[1, 2, 3]
[1, 3, 2]
[2, 1, 3]
[2, 3, 1]
[3, 1, 2]
[3, 2, 1]
-> 6

N이 2일때 경우의 수
[1, 2]
[2, 1]
-> 2

N이 1일때 경우의 수
[1]
-> 1

결론적으로 특정 N의 경우의 수는 N!이 된다.
그리고 사람을 나열 하는 방법이 사전 순이기에
K=1 이면 첫번째 수는 무조건 1이된다.
즉, N과 K에 따라서 첫번째 수를 알 수 있다.

N=3, K=1일때
첫번째 수는 1
N=3, k=3일때
첫번째 수는 2
N=3, K=5일때
첫번째 수는 3

이걸 공식으로 하면
K가 fibo(N-1)보다 작거나 같으면 [ 1 ]index
K%fibo(N-1)이 나머지가 0이면 [ k/fibo(N-1) ]index
아니면 [ k/fibo(N-1) + 1 ]index

여기서 index인 이유는
[0, 1, 2, 3 ,4]에서 2번 인덱스를 사용하면 [0, 1, 3 ,4] 업데이트하여
그 다음번째 수를 구하기 위해서이다.

예시)
N=4, k=12일때 첫번째 수는 2가 나와야한다.
Fibo(N-1) = 6이다.

12%6 == 0이기에 12/6 = 2 index가 첫번째 수가 된다.

다음 두번째 수를 구하기 위해서 [0, 1, 3 ,4] 로 table을 업데이트한다.
그리고 K를 업데이트 한다.
N=4에대한 K=12를 구했다.
이제 N=3일때의 K를 구해야한다.

k%Fibo(n-1)이 0이면 K = (k-1)%Fibo(n-1) +1
아니면 K = k%Fibo(n-1)

K = 6이 된다.
그래서 두번째 수는 [0, 1, 3 ,4]에서 4가 된다.

이렇게 N, N-1, N-2..까지 K와 N을 업데이트하면서 구하면 된다.

*/
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long k) {
  vector<int> answer(n, 0);

  vector<long long> fibo(n, 0);

  vector<int> table(n, 0);
  vector<bool> used(n + 1, false);

  fibo[0] = 1;
  for (int f = 1; f < n; ++f) {
    fibo[f] = fibo[f - 1] * f;
    table[f - 1] = f;
  }
  table[n - 1] = n;

  int idx = 0;
  for (int f = n - 1; f > 0; --f) {
    long long num = fibo[f];
    int tidx;

    if (k <= num)
      tidx = 1;
    else {
      if (k % num == 0)
        tidx = k / num;
      else
        tidx = k / num + 1;
    }

    answer[idx] = table[tidx - 1];
    used[table[tidx - 1]] = true;

    vector<int> temp;
    for (int t = 0; t < table.size(); ++t) {
      if (t != tidx - 1) temp.push_back(table[t]);
    }
    table = vector<int>(temp.begin(), temp.end());

    ++idx;
    if (k % num == 0)
      k = (k - 1) % num + 1;
    else
      k = k % num;
  }

  for (int i = 1; i <= n; ++i) {
    if (!used[i]) answer[n - 1] = i;
  }

  return answer;
}