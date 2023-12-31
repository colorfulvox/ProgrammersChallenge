/*
dp 문제이다.

[14, 6, 5, 11, 3, 9, 2, 10]일때,

1. 첫번째 14를 선택하면 6과 10은 반드시 선택하지 못한다.
2. 두번째 6을 선택하면 반드시 첫번째 14는 선택할 수 없다.

그래서 첫번째를 선택하는 경우와 두번째 선택하는 경우를 나눠서 생각해야한다.


[14, 14, 5, 11, 3, 9, 2, 0] : 첫번째 14를 선택할 경우
(두번째가 14가 된 이유는 어차피 두번째를 선택하지 못한다.
그래서 다음 연산을 위해서 14로 저장한다.)

[0, 6, 5, 11, 3, 9, 2, 10] : 두번째 6을 선택할 경우
(여기서는 첫번째를 0으로 둔다.)

연산 방식
3번째부터(idx : 2) 연산을 시작하는데,
예를들어 연산할때 현재 idx를 선택하면 그전의 idx-1은 선택할 수 없다.
5를 선택할 경우 그전의 6은 선택할 수 없다. (선택할 수도 있다.)

대신, 그전전번째 idx-2 선택할 수 있다.
5를 선택할 경우 14를 선택할 수 있다.

그래서,
만약에 선택할 수 없는 idx-1이 idx-2 + idx보다 크면 idx-1를 선택해야한다.
아닐 경우 [idx-2] + [idx]를 저장한다.

ex)
[14, 14, 5, 11, 3, 9, 2, 0]
이 논리로 3번째부터 연산을 한다.

1. idx : 2 => 5
[14] + [5] > [14] 이기에 19를 저장한다.
[14, 14, 19, 11, 3, 9, 2, 0]

2. idx : 3 => 11
[14] + [11] > [19] 이기에 25를 저장한다.
[14, 14, 19, 25, 3, 9, 2, 0]

3. idx : 4 => 3
[19] + [3] < [25] 이기에 25를 저장한다.
[14, 14, 19, 25, 25, 9, 2, 0]

4. idx : 5 => 9
[25] + [9] > [25] 이기에 34를 저장한다.
[14, 14, 19, 25, 25, 34, 2, 0]

5. idx : 6 => 2
[25] + [2] < [34] 이기에 34를 저장한다.
[14, 14, 19, 25, 25, 34, 34, 0]

6. idx : 7 => 0
[34] + [0] == [34] 이기에 34를 저장한다.
[14, 14, 19, 25, 25, 34, 34, 34]

첫번째 14를 선택할 경우 34가 최대가 된다.

두번째 선택하는 경우
[0, 6, 5, 11, 3, 9, 2, 10]를 연산하면
[0, 6, 6, 17, 17, 26, 26, 36]가 나오며

두번째 6을 선택할 경우 36이 최대가 된다.

이렇게 두개의 경우의 수 중 가장 큰 36이 답이 된다.

*/

#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> sticker) {
  int answer = 0;

  if (sticker.size() == 1) return sticker[0];
  if (sticker.size() == 2)
    return sticker[0] > sticker[1] ? sticker[0] : sticker[1];

  vector<int> st1(sticker.begin(), sticker.end());  // 첫번째를 선택하는 경우
  vector<int> st2(sticker.begin(), sticker.end());  // 두번째를 선택하는 경우

  st1[st1.size() - 1] = 0;
  st1[1] = st1[0];

  st2[0] = 0;

  for (int i = 2; i < st1.size(); ++i) {
    if (st1[i - 2] + st1[i] >= st1[i - 1])
      st1[i] = st1[i - 2] + st1[i];
    else
      st1[i] = st1[i - 1];
  }

  for (int i = 2; i < st2.size(); ++i) {
    if (st2[i - 2] + st2[i] >= st2[i - 1])
      st2[i] = st2[i - 2] + st2[i];
    else
      st2[i] = st2[i - 1];
  }

  //     for(int i=0;i<st1.size();++i)
  //     {
  //         cout<<st1[i]<<" ";
  //     }
  //     cout<<endl;

  //     for(int i=0;i<st2.size();++i)
  //     {
  //         cout<<st2[i]<<" ";
  //     }
  //     cout<<endl;

  if (st1.back() > st2.back())
    answer = st1.back();
  else
    answer = st2.back();

  return answer;
}