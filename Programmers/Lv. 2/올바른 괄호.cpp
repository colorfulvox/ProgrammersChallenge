#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
  bool answer = true;

  vector<bool> st;

  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == '(')
      st.push_back(true);

    else {
      if (st.size() > 0)
        st.pop_back();
      else {
        answer = false;
        break;
      }
    }
  }
  if (st.size() > 0) answer = false;

  return answer;
}