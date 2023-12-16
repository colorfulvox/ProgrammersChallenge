#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string solution(string my_string, vector<vector<int>> queries) {
  string answer = "";

  for (int i = 0; i < queries.size(); ++i) {
    int s = queries[i][0];
    int e = queries[i][1];
    string temp = my_string.substr(s, e - s + 1);
    reverse(temp.begin(), temp.end());
    my_string = my_string.substr(0, s) + temp + my_string.substr(e + 1);
  }
  answer = my_string;
  return answer;
}