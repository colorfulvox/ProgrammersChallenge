#include <string>
#include <vector>

using namespace std;

string textpush(string A) {
  string temp = A;

  char t = temp[temp.length() - 1];
  for (int i = temp.length() - 1; i > 0; --i) temp[i] = temp[i - 1];
  temp[0] = t;

  return temp;
}

int solution(string A, string B) {
  int answer = -1;
  if (A == B) return 0;
  string temp = A;
  for (int c = 1; c <= temp.length(); ++c) {
    temp = textpush(temp);
    if (temp == B) {
      answer = c;
      break;
    }
  }

  return answer;
}