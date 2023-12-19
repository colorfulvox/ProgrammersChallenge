#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
  int answer = 0;

  for (int b = 0; b < babbling.size(); ++b) {
    string ba = babbling[b];
    string temp = "";
    string before = "";
    bool flag = true;
    for (int i = 0; i < ba.length(); ++i) {
      temp += ba[i];

      if (temp == "aya" || temp == "ye" || temp == "woo" || temp == "ma") {
        if (temp == before) {
          flag = false;
          break;
        }
        before = temp;
        temp = "";
      }
    }
    if (temp.length() > 0) flag = false;
    if (flag) ++answer;
  }

  return answer;
}