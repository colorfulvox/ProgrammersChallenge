#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
  vector<int> answer;

  int _size = arr.size();
  if (_size > 1) {
    int two = 2;

    while (two < _size) two *= 2;

    for (int i = 0; i < two - _size; ++i) arr.push_back(0);
  }
  answer = arr;

  return answer;
}