// 1 2 3 4 5 에서 [4, 3, 1, 2, 5]로 stack을 통해 몇개가 되는지 검사

#include <stack>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> order) {
  int answer = 0;

  vector<int> origin(order.size() + 1, 0);
  for (int i = 1; i < origin.size(); ++i) origin[i] = i;

  stack<int> st;
  int idx = 1;

  for (int i = 0; i < order.size();) {
    int target = order[i];

    while (idx < origin.size() && origin[idx] <= target) {
      st.push(origin[idx]);
      ++idx;
    }

    if (st.size() > 0) {
      if (st.top() == target) {
        ++answer;
        st.pop();
        ++i;
        continue;
      } else
        break;
    }
  }

  return answer;
}