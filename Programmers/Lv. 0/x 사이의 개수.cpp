#include <string>
#include <vector>

using namespace std;

vector<int> solution(string myString) {
  vector<int> answer;

  int tsize = 0;

  for (auto word = myString.begin(); word < myString.end(); ++word) {
    if (*word == 'x') {
      answer.push_back(tsize);
      tsize = 0;
    } else
      tsize++;
  }
  answer.push_back(tsize);

  return answer;
}