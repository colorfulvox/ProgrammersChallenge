
#include <stack>
#include <string>
#include <vector>
using namespace std;

int solution(string s) {
  int answer = 1;

  stack<char> st;

  for (auto w : s) {
    if (st.size()) {
      if (st.top() == w)
        st.pop();
      else
        st.push(w);
    } else
      st.push(w);
  }
  if (st.size()) answer = 0;

  return answer;
}