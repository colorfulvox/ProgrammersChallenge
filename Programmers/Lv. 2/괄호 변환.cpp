#include <stack>
#include <string>
#include <vector>

using namespace std;

string func(string temp) {
  if (temp == "") return "";

  int idx = 0;
  int cnt = 0;

  for (int t = 0; t < temp.length(); ++t) {
    if (temp[t] == '(')
      ++cnt;
    else
      --cnt;
    if (cnt == 0) {
      idx = t;
      break;
    }
  }

  string u = temp.substr(0, idx + 1);
  string v = temp.substr(idx + 1);

  stack<int> st;
  bool flag = true;
  for (int i = 0; i < u.length(); ++i) {
    if (u[i] == '(')
      st.push(1);
    else {
      if (st.size())
        st.pop();
      else {
        flag = false;
        break;
      }
    }
  }
  if (st.size()) flag = false;

  if (flag) {
    return u + func(v);
  } else {
    string tm = "";
    tm += '(';
    tm = tm + func(v);
    tm += ')';
    string ut = u.substr(1, u.length() - 2);
    for (int i = 0; i < ut.length(); ++i) {
      if (ut[i] == '(')
        tm += ')';
      else
        tm += '(';
    }
    return tm;
  }
}

string solution(string p) {
  string answer = func(p);
  return answer;
}