#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
  vector<int> answer;

  string temp = to_string(n);
  for (auto tm = temp.end() - 1; tm >= temp.begin(); --tm) {
    answer.push_back(*tm - '0');
  }

  return answer;
}