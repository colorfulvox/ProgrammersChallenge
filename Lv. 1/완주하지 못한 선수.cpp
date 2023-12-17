#include <map>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
  string answer = "";

  map<string, int> table;

  for (auto par = participant.begin(); par < participant.end(); ++par)
    table[*par]++;

  for (auto com = completion.begin(); com < completion.end(); ++com) {
    table[*com]--;
  }
  for (auto k : table) {
    if (k.second > 0) {
      answer = k.first;
      break;
    }
  }

  return answer;
}