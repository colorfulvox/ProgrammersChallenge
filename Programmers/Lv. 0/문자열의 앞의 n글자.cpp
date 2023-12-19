#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int n) {
  string answer = "";

  for (int i = 0; i < my_string.length(); ++i) {
    answer += my_string[i];
    if (i + 1 == n) break;
  }
  return answer;
}