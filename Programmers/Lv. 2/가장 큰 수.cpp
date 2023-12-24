/*
30과 4일때

304, 403 중 큰 값을 고르면된다.
403을 고를경우 4가 먼저 나오면 된다.
*/

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool cmp(string a, string b) {
  string t1 = a + b;
  string t2 = b + a;
  if (t1 > t2)
    return true;
  else
    return false;
}

string solution(vector<int> numbers) {
  string answer = "";

  vector<string> table;
  for (int i = 0; i < numbers.size(); ++i)
    table.push_back(to_string(numbers[i]));

  sort(table.begin(), table.end(), cmp);
  if (table[0] == "0") return "0";
  for (int i = 0; i < table.size(); ++i) {
    answer += table[i];
  }
  return answer;
}