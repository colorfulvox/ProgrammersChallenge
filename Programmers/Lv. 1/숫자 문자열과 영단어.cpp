#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
  int answer = 0;

  map<string, int> table;
  table["zero"] = 0;
  table["one"] = 1;
  table["two"] = 2;
  table["three"] = 3;
  table["four"] = 4;
  table["five"] = 5;
  table["six"] = 6;
  table["seven"] = 7;
  table["eight"] = 8;
  table["nine"] = 9;

  int dig = 1;
  string temp = "";

  for (auto str = s.end() - 1; str >= s.begin(); --str) {
    if (*str >= '0' && *str <= '9') {
      answer += (*str - '0') * dig;
      dig *= 10;
    } else {
      temp += *str;
      string retemp = temp;
      reverse(retemp.begin(), retemp.end());
      if (table.find(retemp) != table.end()) {
        answer += table[retemp] * dig;
        dig *= 10;
        temp = "";
      }
    }
  }

  return answer;
}