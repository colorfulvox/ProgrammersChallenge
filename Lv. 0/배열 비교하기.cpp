#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr1, vector<int> arr2) {
  int answer = 0;

  if (arr1.size() > arr2.size()) answer = 1;
  if (arr1.size() < arr2.size()) answer = -1;
  if (arr1.size() == arr2.size()) {
    int arr1sum = 0;
    int arr2sum = 0;

    for (int i = 0; i < arr1.size(); ++i) {
      arr1sum += arr1[i];
      arr2sum += arr2[i];
    }
    if (arr1sum > arr2sum) answer = 1;
    if (arr1sum < arr2sum) answer = -1;
  }

  return answer;
}