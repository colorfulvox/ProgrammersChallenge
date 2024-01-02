/*
1. 숫자만 넣은 dq, 연산자만 넣는 oper를 생성해 순서대로 넣는다.
2. 연산자 table을 돌리면서 최대값을 구할것이다.
3. 만약 첫번째 연산자가 oper.front와 다를경우 oper.front의 연산자를
뒤로 옮기고 dq 숫자 front도 뒤로 넘긴다.
4. 만약 같다면  dq.front의 숫자 두개를 빼서 oper.front로 연산한뒤
oper.front는 pop을하고 연산한 숫자는 다시 dq.front앞에 push한다.

한번 연산을 마치면 dq의 순서를 다시 정리하기위해 dq.front를 back으로 옮긴다.

모든 연산을 마친뒤 dq.front의 숫자가 최대값이된다.


예시)
"100-200*300-500+20"

dq = [100, 200, 300, 500, 20]
oper = [-,*,-,+]

사용할 연산 테이블 *,+,-
*연산 수행

1. oper front : - != *
연산자가 다르기에 dq, oper를 업데이트한다.
dq = [200, 300, 500, 20, 100]
oper = [*,-,+,-]

2. oper front : * == *
연산자가 같기에 연산한다.
dq => 200 * 300 = 60000

dq = [60000, 500, 20, 100]
oper = [-,+,-]

3. oper front : - != *
다르기에 업데이트한다.

dq = [500, 20, 100, 60000]
oper = [+,-,-]

4. oper front : + != *
다르기에 업데이트한다.

dq = [20, 100, 60000, 500]
oper = [-,-,+]

5. *의 연산이 끝났다.
마지막으로 dq를 다시 한번 업데이트한뒤
다음 연산자 +를 수행하고 -까지 반복하면 -60420가 나온다.
dq = [100, 60000, 500, 20]

*/

#include <cmath>
#include <deque>
#include <string>
#include <vector>

using namespace std;

char table[6][3] = {{'*', '-', '+'}, {'*', '+', '-'}, {'-', '*', '+'},
                    {'-', '+', '*'}, {'+', '-', '*'}, {'+', '*', '-'}};

long long solution(string expression) {
  long long answer = 0;

  deque<long long> o_dq;
  deque<char> o_oper;

  string snum = "";
  for (int e = 0; e < expression.length(); ++e) {
    if (expression[e] >= '0' && expression[e] <= '9')
      snum += expression[e];
    else {
      o_oper.push_back(expression[e]);
      long long num = stoll(snum);
      o_dq.push_back(num);
      snum = "";
    }
  }
  o_dq.push_back(stoll(snum));

  for (int t = 0; t < 6; ++t) {
    deque<long long> dq = deque<long long>(o_dq.begin(), o_dq.end());
    deque<char> oper = deque<char>(o_oper.begin(), o_oper.end());

    for (int p = 0; p < 3; ++p) {
      char op = table[t][p];
      int cnt = oper.size();

      while (cnt--) {
        if (!oper.size()) break;

        if (op != oper.front()) {
          char temp = oper.front();
          oper.pop_front();
          oper.push_back(temp);

          long long num = dq.front();
          dq.pop_front();
          dq.push_back(num);
        } else {
          oper.pop_front();

          long long num;

          long long num1 = dq.front();
          dq.pop_front();
          long long num2 = dq.front();
          dq.pop_front();

          if (op == '+') num = num1 + num2;
          if (op == '*') num = num1 * num2;
          if (op == '-') num = num1 - num2;

          dq.push_front(num);
        }
      }

      long long num = dq.front();
      dq.pop_front();
      dq.push_back(num);
    }

    if (answer < abs(dq.front())) answer = abs(dq.front());
  }

  return answer;
}