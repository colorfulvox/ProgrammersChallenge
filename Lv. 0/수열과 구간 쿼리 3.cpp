#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
  vector<int> answer;

  for (int q = 0; q < queries.size(); ++q) {
    int temp = arr[queries[q][1]];
    arr[queries[q][1]] = arr[queries[q][0]];
    arr[queries[q][0]] = temp;
  }
  answer = arr;

  return answer;
}