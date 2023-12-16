#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
  int answer = 0;
  int cnt = 0;
  int dat[1001] = {0};
  for (auto arr = array.begin(); arr < array.end(); ++arr) {
    dat[*arr]++;
    if (cnt < dat[*arr]) {
      answer = *arr;
      cnt = dat[*arr];
    }
  }

  for (int i = 0; i < 1001; ++i) {
    if (answer != i && cnt == dat[i]) {
      answer = -1;
      break;
    }
  }

  return answer;
}