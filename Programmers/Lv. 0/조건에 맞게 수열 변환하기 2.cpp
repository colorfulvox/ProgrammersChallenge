#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
  int answer = 0;

  vector<int> table = vector<int>(arr.begin(), arr.end());

  while (true) {
    bool flag = true;
    for (int i = 0; i < table.size(); ++i) {
      if (table[i] > 50 && table[i] % 2 == 0) {
        table[i] /= 2;
        if (table[i] != arr[i]) {
          flag = false;
          arr[i] = table[i];
        }
      } else if (table[i] < 50 && table[i] % 2 != 0) {
        table[i] *= 2;
        table[i]++;
        if (table[i] != arr[i]) {
          flag = false;
          arr[i] = table[i];
        }
      }
    }

    if (flag)
      break;
    else
      answer++;
  }

  return answer;
}