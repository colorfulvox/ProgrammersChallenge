#include <string>
#include <vector>

using namespace std;

string solution(int age) {
  string answer = "";

  string temp = to_string(age);
  for (auto t = temp.begin(); t < temp.end(); ++t) {
    answer += 'a' + (*t - '0');
  }

  return answer;
}