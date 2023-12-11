#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list, int n) {
  vector<int> answer;

  for (auto num = num_list.begin() + n; num < num_list.end(); ++num)
    answer.push_back(*num);

  for (auto num = num_list.begin(); num < num_list.begin() + n; ++num)
    answer.push_back(*num);
  return answer;
}