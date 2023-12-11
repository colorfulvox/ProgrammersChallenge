#include <string>
#include <vector>

using namespace std;

string solution(string rny_string) {
  string answer = "";

  for (auto rny = rny_string.begin(); rny < rny_string.end(); ++rny) {
    if (*rny == 'm') {
      answer += 'r';
      answer += 'n';
    } else
      answer += *rny;
  }

  return answer;
}