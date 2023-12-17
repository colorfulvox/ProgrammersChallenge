/*
1. 문자열 맨 뒤부터 문자를 검사한다.
2. 점수 계산 시점은 '*', '#', 'S','D','T'를 받을때와 마지막에 한번더 검사한다.
3. 여기서 *는 중첩이 된다. 그래서 *가 발견되면 stack에 2, 2 두개를 저장한다.
4. 단, 만약 stack에 갯수가 1개뿐이라면 이미 한번 사용을 했고 그 상황에서 *가
발견된거기에 중첩되었다는 것이다.
그래서 첫번째 stack top을 (pop)버리고 다음 점수는 중첩된 4로 계산되야한다.
*/

#include <cmath>
#include <iostream>
#include <stack>
#include <string>

using namespace std;
string cmd = "";
string num = "";
bool acha = false;
stack<int> stars;

int check() {
  int score;
  if (num.length() == 2)
    score = 10;
  else
    score = num[0] - '0';
  if (cmd == "D")
    score = pow(score, 2);
  else if (cmd == "T")
    score = pow(score, 3);
  cmd = "";
  num = "";

  if (acha) {
    score *= -1;
    acha = false;
  }
  if (stars.size() > 0) {
    score *= stars.top();
    stars.pop();
  }

  return score;
}

long long solution(string dartResult) {
  long long answer = 0;

  for (auto dart = dartResult.end() - 1; dart >= dartResult.begin(); --dart) {
    if (*dart == '*') {
      if (cmd.length()) answer += check();

      if (stars.size() == 1) {
        stars.pop();
        stars.push(2);
        stars.push(4);

      } else {
        stars.push(2);
        stars.push(2);
      }
    } else if (*dart == '#') {
      if (cmd.length()) answer += check();

      acha = true;
    } else if (*dart >= '0' && *dart <= '9')
      num += *dart;
    else {
      if (cmd.length()) answer += check();

      cmd += *dart;
    }
  }

  if (cmd.length()) answer += check();

  return answer;
}