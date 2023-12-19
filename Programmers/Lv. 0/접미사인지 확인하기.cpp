#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_suffix) {
  int answer = 0;

  string temp = "";

  while (my_string.length()) {
    if (my_string == is_suffix) {
      answer = 1;
      break;
    }
    my_string = my_string.substr(1, my_string.length());
  }

  return answer;
}