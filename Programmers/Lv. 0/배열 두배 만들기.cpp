#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
  vector<int> answer;
  for (auto num = numbers.begin(); num != numbers.end(); num++)
    answer.push_back(*num * 2);
  return answer;
}