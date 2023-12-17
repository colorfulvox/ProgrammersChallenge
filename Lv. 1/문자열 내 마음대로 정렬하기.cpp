#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class strinfo {
 public:
  string str;
  char word;
  strinfo(string _str, char _word) : str(_str), word(_word) {}
};

bool compare(strinfo a, strinfo b) {
  if (a.word == b.word) return a.str < b.str;
  return a.word < b.word;
}

vector<string> solution(vector<string> strings, int n) {
  vector<string> answer;

  vector<strinfo> table;

  for (int i = 0; i < strings.size(); ++i) {
    table.push_back(strinfo(strings[i], strings[i][n]));
  }

  sort(table.begin(), table.end(), compare);

  for (int i = 0; i < table.size(); ++i) answer.push_back(table[i].str);

  return answer;
}