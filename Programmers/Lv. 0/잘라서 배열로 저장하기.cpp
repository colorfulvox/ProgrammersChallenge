#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_str, int n) {
  vector<string> answer;

  for (int i = 0; i < my_str.length(); i += n) {
    if (i + n <= my_str.length())
      answer.push_back(my_str.substr(i, n));
    else
      answer.push_back(my_str.substr(i));
  }

  return answer;
}