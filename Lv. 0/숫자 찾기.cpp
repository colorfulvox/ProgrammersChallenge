#include <string>
#include <vector>

using namespace std;

int solution(int num, int k) {
  int answer = -1;

  string temp = to_string(num);

  for (int i = 0; i < temp.length(); ++i) {
    if (temp[i] == '0' + k) {
      answer = i + 1;
      break;
    }
  }

  return answer;
}