/*


*/



#include <string>
#include <vector>

using namespace std;

int LCM(int a, int b) {
  int tm;
  if (a > b) {
    tm = a;
    a = b;
    b = tm;
  }

  for (int i = b;; ++i) {
    if (i % a == 0 && i % b == 0) return i;
  }
}

int solution(vector<int> arr) {
  int answer = arr[0];

  for (int i = 1; i < arr.size(); ++i) {
    answer = LCM(answer, arr[i]);
  }

  return answer;
}