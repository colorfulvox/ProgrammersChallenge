#include <cmath>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int n) {
  int answer = 0;

  int dis = 21e8;

  for (auto arr = array.begin(); arr < array.end(); ++arr) {
    if (abs(*arr - n) < dis) {
      answer = *arr;
      dis = abs(*arr - n);
    } else if (abs(*arr - n) == dis) {
      if (answer > *arr) answer = *arr;
    }
  }

  return answer;
}