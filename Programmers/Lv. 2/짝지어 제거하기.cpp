#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(string s) {
  int answer = 1;

  vector<char> table;

  for (int i = 0; i < s.length(); ++i) {
    if (table.size() > 0) {
      if (table[table.size() - 1] == s[i])
        table.pop_back();
      else
        table.push_back(s[i]);
    } else
      table.push_back(s[i]);
  }
  if (table.size() > 0) answer = 0;

  return answer;
}