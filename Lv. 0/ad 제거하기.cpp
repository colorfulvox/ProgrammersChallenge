#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strArr) {
  vector<string> answer;

  for (int i = 0; i < strArr.size(); ++i) {
    string temp = "";
    bool flag = true;
    for (auto word = strArr[i].begin(); word < strArr[i].end(); ++word) {
      temp += *word;
      if (temp.length() == 2) {
        if (temp == "ad") {
          flag = false;
          break;
        } else
          temp = *word;
      }
    }

    if (flag) answer.push_back(strArr[i]);
  }

  return answer;
}