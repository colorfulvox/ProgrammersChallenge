#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
  vector<int> answer;

  for (auto ar = arr.begin(); ar < arr.end(); ++ar) {
    if (*ar % divisor == 0) answer.push_back(*ar);
  }
  if (answer.size() > 0)
    sort(answer.begin(), answer.end());
  else
    answer.push_back(-1);

  return answer;
}