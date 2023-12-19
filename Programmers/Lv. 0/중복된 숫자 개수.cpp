#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int n) {
  int answer = 0;

  for (auto arr = array.begin(); arr != array.end(); ++arr) {
    if (*arr == n) ++answer;
  }
  return answer;
}