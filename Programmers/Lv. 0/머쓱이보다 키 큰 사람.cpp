#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int height) {
  int answer = 0;

  for (auto arr = array.begin(); arr != array.end(); arr++) {
    if (*arr > height) ++answer;
  }
  return answer;
}