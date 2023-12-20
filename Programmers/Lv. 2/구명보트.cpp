#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> people, int limit) {
  int answer = 0;
  int left = 0;
  int right = people.size() - 1;

  sort(people.begin(), people.end());

  while (true) {
    if (people[right] + people[left] > limit) {
      --right;
      ++answer;
      if (left == right) {
        ++answer;
        break;
      }
    } else {
      ++answer;
      ++left;
      --right;
      if (left > right)
        break;
      else if (left == right) {
        ++answer;
        break;
      }
    }
  }

  return answer;
}