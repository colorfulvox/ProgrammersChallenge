#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
  vector<int> answer;

  for (int q = 0; q < queries.size(); q++) {
    for (int s = queries[q][0]; s <= queries[q][1]; ++s) {
      if (s % queries[q][2] == 0) arr[s]++;
    }
  }
  answer = arr;

  return answer;
}