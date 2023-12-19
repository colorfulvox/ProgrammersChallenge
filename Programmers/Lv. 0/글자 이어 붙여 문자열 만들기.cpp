#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<int> index_list) {
  string answer = "";

  for (auto index = index_list.begin(); index < index_list.end(); ++index) {
    answer += my_string[*index];
  }
  return answer;
}