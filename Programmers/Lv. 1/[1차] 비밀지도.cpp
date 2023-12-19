#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
  vector<string> answer;

  for (int i = 0; i < arr1.size(); ++i) {
    answer.push_back("");

    string atemp = "";
    int anum = arr1[i];
    while (anum) {
      if (anum % 2 == 0)
        atemp += '0';
      else
        atemp += '1';
      anum /= 2;
    }
    while (atemp.length() < n) atemp += '0';

    string btemp = "";
    int bnum = arr2[i];
    while (bnum) {
      if (bnum % 2 == 0)
        btemp += '0';
      else
        btemp += '1';
      bnum /= 2;
    }
    while (btemp.length() < n) btemp += '0';

    for (int t = atemp.length() - 1; t >= 0; --t) {
      if (atemp[t] == '1' || btemp[t] == '1')
        answer[i] += '#';
      else
        answer[i] += ' ';
    }
  }

  return answer;
}