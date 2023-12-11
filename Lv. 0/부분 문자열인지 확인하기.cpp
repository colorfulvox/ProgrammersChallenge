#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string target) {
  int answer = 0;

  for (int i = 0; i < my_string.length(); ++i) {
    if (i + target.length() <= my_string.length()) {
      string temp = my_string.substr(i, target.length());

      if (temp == target) answer = 1;
    }
  }

  return answer;
}