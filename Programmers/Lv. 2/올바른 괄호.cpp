#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool solution(string s) {
  bool answer = true;

  stack<int> st;

  for (auto w : s) {
    if (w == '(')
      st.push(1);
    else {
      if (st.size())
        st.pop();
      else {
        answer = false;
        break;
      }
    }
  }
  if (st.size()) answer = false;

  return answer;
}