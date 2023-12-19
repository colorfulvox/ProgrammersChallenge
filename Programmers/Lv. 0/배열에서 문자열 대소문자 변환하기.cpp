#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strArr) {
  vector<string> answer;

  for (int i = 0; i < strArr.size(); ++i) {
    string temp = "";

    for (auto word = strArr[i].begin(); word < strArr[i].end(); ++word) {
      if (i % 2 == 0) {
        if (*word >= 'A' && *word <= 'Z')
          temp += *word - 'A' + 'a';
        else
          temp += *word;
      } else {
        if (*word >= 'a' && *word <= 'z')
          temp += *word - 'a' + 'A';
        else
          temp += *word;
      }
    }

    answer.push_back(temp);
  }

  return answer;
}