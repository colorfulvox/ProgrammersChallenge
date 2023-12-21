#include <string>
#include <vector>

using namespace std;

int solution(vector<int> topping) {
  int answer = 0;

  vector<int> a(10001, 0);
  int acnt = 0;
  vector<int> b(10001, 0);
  int bcnt = 0;

  for (int t = 0; t < topping.size(); ++t) {
    if (a[topping[t]] == 0) ++acnt;
    a[topping[t]]++;
  }
  for (int t = 0; t < topping.size(); ++t) {
    if (b[topping[t]] == 0) ++bcnt;
    b[topping[t]]++;

    a[topping[t]]--;
    if (a[topping[t]] == 0) --acnt;

    if (bcnt == acnt) ++answer;
  }

  return answer;
}