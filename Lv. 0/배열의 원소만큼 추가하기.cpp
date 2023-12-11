#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
  vector<int> answer;

  for (auto a = arr.begin(); a < arr.end(); ++a) {
    for (int i = 0; i < *a; ++i) answer.push_back(*a);
  }

  return answer;
}