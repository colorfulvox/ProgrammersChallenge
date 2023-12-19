#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> strlist) {
  vector<int> answer = vector<int>(strlist.size(), 0);
  for (int i = 0; i < strlist.size(); ++i) answer[i] = strlist[i].length();
  return answer;
}