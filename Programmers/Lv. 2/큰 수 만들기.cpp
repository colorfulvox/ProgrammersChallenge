/*
1. 일단 answer에 첫번째를 넣는다.
2. answer마지막자리가 다음 숫자보다 작으면 k && answer.length() 조건동안
계속 answer의 마지막자리를 뺀다.
3. 그리고 다음 숫자를 넣은다.

마지막에 k가 남을경우 answer 마지막을 k만큼자른다.

"4177252841"  k =4

1. 4
2. 4 1
3. 7 등장 4, 1 빼버림 : 7  | k =2
4. 7 7
5. 7 7 2
6. 5 등장 2 빼버림 : 7 7 5 | k =1
7. 7 7 5 2
8. 8 등장 2 빼버림 : 7 7 5 8 | k가 2를 빼면서 0이되어 5는 안뺌
9. 7 7 5 8 4 1

*/

#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
  string answer = "";
  answer = number[0];

  for (int i = 1; i < number.length(); ++i) {
    if (k) {
      while (k && answer.length() && answer.back() < number[i]) {
        answer.pop_back();
        --k;
      }
    }
    answer += number[i];
  }

  answer = answer.substr(0, answer.length() - k);

  return answer;
}