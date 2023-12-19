#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
  int answer = 0;

  int odd = 0;
  int even = 0;

  for (int i = 0; i < num_list.size(); ++i) {
    if ((i + 1) % 2 == 0)
      even += num_list[i];
    else
      odd += num_list[i];
  }
  if (odd < even)
    answer = even;
  else
    answer = odd;

  return answer;
}