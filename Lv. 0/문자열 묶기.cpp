#include <string>
#include <vector>

using namespace std;

int solution(vector<string> strArr) {
  int answer = 0;

  int dat[100001] = {0};

  for (int i = 0; i < strArr.size(); ++i) {
    dat[strArr[i].length()]++;
    if (answer < dat[strArr[i].length()]) answer = dat[strArr[i].length()];
  }

  return answer;
}