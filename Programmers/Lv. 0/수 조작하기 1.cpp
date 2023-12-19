#include <string>
#include <vector>

using namespace std;

int solution(int n, string control) {
  int answer = n;

  for (auto con = control.begin(); con < control.end(); ++con) {
    if (*con == 'w')
      answer++;
    else if (*con == 's')
      answer--;
    else if (*con == 'd')
      answer += 10;
    else
      answer -= 10;
  }

  return answer;
}