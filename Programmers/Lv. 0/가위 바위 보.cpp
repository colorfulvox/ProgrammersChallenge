#include <string>
#include <vector>

using namespace std;

string solution(string rsp) {
  string answer = "";

  for (auto r = rsp.begin(); r != rsp.end(); ++r) {
    if (*r == '2') answer += '0';
    if (*r == '0') answer += '5';
    if (*r == '5') answer += '2';
  }

  return answer;
}