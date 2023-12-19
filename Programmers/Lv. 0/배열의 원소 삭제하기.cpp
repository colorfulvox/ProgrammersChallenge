#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> delete_list) {
  vector<int> answer;

  vector<bool> used = vector<bool>(1001, false);

  for (auto a = arr.begin(); a < arr.end(); ++a) used[*a] = true;

  for (auto d = delete_list.begin(); d < delete_list.end(); ++d)
    used[*d] = false;

  for (auto a = arr.begin(); a < arr.end(); ++a) {
    if (used[*a]) answer.push_back(*a);
  }

  return answer;
}