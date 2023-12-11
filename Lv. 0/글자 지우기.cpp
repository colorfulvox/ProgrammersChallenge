#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<int> indices) {
  string answer = "";

  vector<bool> check(101, false);
  for (auto in = indices.begin(); in < indices.end(); ++in) {
    check[*in] = true;
  }

  for (int i = 0; i < my_string.length(); ++i) {
    if (check[i]) continue;
    answer += my_string[i];
  }

  return answer;
}