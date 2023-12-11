#include <string>
#include <vector>

using namespace std;

string solution(vector<string> str_list, string ex) {
  string answer = "";

  for (int i = 0; i < str_list.size(); ++i) {
    bool flag = true;
    for (int s = 0; s < str_list[i].length(); ++s) {
      if (s + ex.length() <= str_list[i].length()) {
        string temp = str_list[i].substr(s, ex.length());
        if (temp == ex) {
          flag = false;
          break;
        }
      }
    }
    if (flag) answer += str_list[i];
  }

  return answer;
}