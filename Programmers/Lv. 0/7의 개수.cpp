#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
  int answer = 0;

  for (auto ar = array.begin(); ar < array.end(); ++ar) {
    string temp = to_string(*ar);
    for (auto tm = temp.begin(); tm < temp.end(); ++tm) {
      if (*tm == '7') ++answer;
    }
  }

  return answer;
}