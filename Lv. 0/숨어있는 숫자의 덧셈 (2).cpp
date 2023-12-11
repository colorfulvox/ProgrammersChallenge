#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
  int answer = 0;

  string temp = "";
  for (auto my = my_string.begin(); my < my_string.end(); ++my) {
    if (*my >= '0' && *my <= '9')
      temp += *my;
    else {
      if (temp.length() > 0) {
        answer += stoi(temp);
        temp = "";
      }
    }
  }
  if (temp.length() > 0) answer += stoi(temp);

  return answer;
}