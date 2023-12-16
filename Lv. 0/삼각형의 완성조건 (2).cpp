#include <string>
#include <vector>

using namespace std;

int solution(vector<int> sides) {
  int answer = 0;

  if (sides[0] > sides[1]) {
    int temp = sides[0];
    sides[0] = sides[1];
    sides[1] = temp;
  }

  for (int i = 1; i <= sides[1]; ++i) {
    if (sides[0] + i > sides[1]) ++answer;
  }

  answer += (sides[0] + sides[1]) - (sides[1] + 1);

  return answer;
}