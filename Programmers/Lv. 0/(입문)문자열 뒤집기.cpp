#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string solution(string my_string) {
  reverse(my_string.begin(), my_string.end());
  string answer = my_string;
  return answer;
}