#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
  double answer = 0;

  for (auto ar = arr.begin(); ar < arr.end(); ++ar) {
    answer += *ar;
  }
  answer /= arr.size();

  return answer;
}