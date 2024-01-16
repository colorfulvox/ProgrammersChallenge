#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
  string answer = "";

  int start = 0, end = 0;

  vector<int> lst;

  while ((end = s.find(' ', start)) != string::npos) {
    int num = stoi(s.substr(start, end - start));
    lst.push_back(num);
    start = end + 1;
  }
  int num = stoi(s.substr(start));
  lst.push_back(num);

  sort(lst.begin(), lst.end());

  answer += to_string(lst[0]) + ' ' + to_string(lst[lst.size() - 1]);

  return answer;
}