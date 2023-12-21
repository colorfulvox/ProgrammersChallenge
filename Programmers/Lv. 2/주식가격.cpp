/*
3초 시점의 ₩3은 1초뒤에 가격이 떨어집니다.
따라서 1초간 가격이 떨어지지 않은 것으로 봅니다.

이 지문이 헷갈린다.

간단하게 말해서 가격이 떨어지는 시점까지만 계산하면 된다.
근데 만약 떨어지는 시점이 있을 경우 자기 자신도 1초로 간주한다.

예시에서

1,2,3,2,3 -> 4,3,1,1,0 일때,
1 2 3 4 5

3초에서 4초로 갈때 가격이 떨어지니까
4초 이후 가격은 보지 않는다.
그리고 3초에서 4초로 가기직전에 3초 시점에서
가격을 유지하는거라 판단하고 1초를 증가시킨다.
*/

#include <algorithm>
#include <stack>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
  vector<int> answer;

  stack<int> st;

  for (int i = prices.size() - 1; i >= 0; --i) {
    if (st.size() == 0)
      answer.push_back(0);
    else {
      stack<int> tt;
      int cnt = 0;
      while (st.size()) {
        if (st.top() < prices[i]) {
          ++cnt;
          break;
        }
        tt.push(st.top());
        st.pop();
        ++cnt;
      }

      while (tt.size()) {
        st.push(tt.top());
        tt.pop();
      }
      answer.push_back(cnt);
    }
    st.push(prices[i]);
  }
  reverse(answer.begin(), answer.end());

  return answer;
}