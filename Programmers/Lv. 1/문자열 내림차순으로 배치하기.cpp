#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
  string answer = "";
  sort(s.begin(), s.end());
  reverse(s.begin(), s.end());
  answer = s;
  return answer;
}