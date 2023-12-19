#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
  sort(array.begin(), array.end());
  int answer = array[array.size() / 2];
  return answer;
}