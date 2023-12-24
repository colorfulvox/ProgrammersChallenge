/*
0index는 0으로 두고 누적합을 구한다.

[1, 2, 3, 4, 5]  => [0, 1, 3, 6, 10, 15]
                     0  1  2  3   4  5]

누적합에서

left = 0
right =0
를 시작으로 right - left 값이 k와 같은지 조사한다.
k=7

1. [0] - [0] = 0 | k보다 작으니 right 증가
2. [1] - [0] = 1 | k보다 작으니 right 증가
3. [2] - [0] = 3 | k보다 작으니 right 증가
4. [3] - [0] = 6 | k보다 작으니 right 증가
5. [4] - [0] = 10 | k보다 크니 left 증가
6. [4] - [1] = 9 | k보다 크니 left 증가
7. [4] - [2] = 7 | k랑 같으니 left, right-1이 answer에 저장, right 증가
8. [5] - [2] = 12 | k보다 크니 left 증가
9. [5] - [3] = 9 | k보다 크니 left 증가
10. [5] - [4] = 5 | k보다 작으니 right 증가
11. [5] - [5] = 0 | k보드 작으니 right 증가

right가 table.size()보다 크니 종료
answer = 2, 3
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
  vector<int> answer(2, -1);

  vector<int> table(sequence.size() + 1, 0);

  for (int i = 1; i < table.size(); ++i) {
    table[i] = table[i - 1] + sequence[i - 1];
  }

  int left = 0, right = 0;

  while (left <= right) {
    int num = table[right] - table[left];

    if (num == k) {
      if (answer[0] == -1) {
        answer[0] = left;
        answer[1] = right - 1;
      } else {
        if (answer[1] - answer[0] > (right - 1) - left) {
          answer[0] = left;
          answer[1] = right - 1;
        } else if (answer[1] - answer[0] == (right - 1) - left) {
          if (answer[0] > left) {
            answer[0] = left;
            answer[1] = right - 1;
          }
        }
      }
      ++left;
    } else if (num > k) {
      ++left;
    } else {
      if (right + 1 == table.size())
        ++left;
      else
        ++right;
    }
  }

  return answer;
}