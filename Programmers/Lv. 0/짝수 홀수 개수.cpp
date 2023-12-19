#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
  vector<int> answer = vector<int>(2, 0);

  for (auto num = num_list.begin(); num != num_list.end(); ++num) {
    if (*num % 2 == 0)
      answer[0]++;
    else
      answer[1]++;
  }

  return answer;
}