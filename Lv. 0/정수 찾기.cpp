#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list, int n) {
  int answer = 0;
  for (auto num = num_list.begin(); num < num_list.end(); ++num) {
    if (*num == n) answer = 1;
  }
  return answer;
}