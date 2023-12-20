
// yellow의 약수중 제일 큰 짝
// (단, brown + yellow 랑 해당 y*x 크기가 같아야 된다.)
/*
6의 약수 1 2 3 6
하지만, brown 갯수에따라 1,6이 될지 2,3이 될지 결졍된다.

B B B B B B B B
B Y Y Y Y Y Y B  => 18 + 6 =24
B B B B B B B B

B B B B B
B Y Y Y B
B Y Y Y B  => 14 + 6 = 20
B B B B B
*/
#include <cmath>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
  vector<int> answer;

  int n = 21e8;
  for (int i = 1; i <= sqrt(yellow); ++i) {
    if (yellow % i == 0) {
      int temp = yellow / i;
      if (temp < n) {
        if (brown + yellow == (temp + 2) * (yellow / temp + 2)) n = yellow / i;
      }
    }
  }
  answer.push_back(n + 2);
  answer.push_back(yellow / n + 2);

  return answer;
}