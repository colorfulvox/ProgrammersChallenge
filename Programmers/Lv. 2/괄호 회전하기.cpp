#include <stack>
#include <string>
#include <vector>

using namespace std;

string cycle(string temp) {
  char tm = temp[0];
  for (int i = 0; i < temp.length() - 1; ++i) temp[i] = temp[i + 1];
  temp[temp.length() - 1] = tm;

  return temp;
}

int solution(string s) {
  int answer = 0;

  for (int c = 0; c < s.length(); ++c) {
    stack<char> st;
    bool flag = true;
    for (int i = 0; i < s.length(); ++i) {
      if (st.size() == 0) {
        if (s[i] == '[' || s[i] == '{' || s[i] == '(')
          st.push(s[i]);
        else {
          flag = false;
          break;
        }
      } else {
        if (s[i] == '[' || s[i] == '{' || s[i] == '(')
          st.push(s[i]);
        else {
          if (st.top() == '[' && s[i] != ']') {
            flag = false;
            break;
          }
          if (st.top() == '{' && s[i] != '}') {
            flag = false;
            break;
          }
          if (st.top() == '(' && s[i] != ')') {
            flag = false;
            break;
          }
          st.pop();
        }
      }
    }
    s = cycle(s);
    if (st.size() > 0 || !flag)
      continue;
    else
      ++answer;
  }

  return answer;
}