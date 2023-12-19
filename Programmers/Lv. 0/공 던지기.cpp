#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k) {
  int answer = 1;

  while (--k) {
    if (answer + 2 > numbers.size())
      answer = (answer + 2) - numbers.size();
    else
      answer += 2;
  }
  answer = numbers[answer - 1];

  return answer;
}