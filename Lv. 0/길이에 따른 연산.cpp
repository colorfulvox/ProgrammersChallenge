#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
  int answer = 0;
  if (num_list.size() > 10) {
    for (auto num = num_list.begin(); num < num_list.end(); ++num)
      answer += *num;
  } else {
    answer = 1;
    for (auto num = num_list.begin(); num < num_list.end(); ++num)
      answer *= *num;
  }
  return answer;
}