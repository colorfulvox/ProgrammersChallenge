#include <string>
#include <vector>

using namespace std;

vector<string> solution(string myStr) {
  vector<string> answer;

  string temp = "";
  for (auto my = myStr.begin(); my < myStr.end(); ++my) {
    if (*my == 'a' || *my == 'b' || *my == 'c') {
      if (temp.length() > 0) {
        answer.push_back(temp);
        temp = "";
      }

    } else
      temp += *my;
  }
  if (temp.length() > 0) answer.push_back(temp);
  if (answer.size() == 0) answer.push_back("EMPTY");

  return answer;
}