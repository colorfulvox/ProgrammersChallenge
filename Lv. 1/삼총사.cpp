#include <string>
#include <vector>

using namespace std;
int answer = 0;
void func(vector<int> num, int idx, int level, int sum) {
  if (level == 3) {
    if (sum == 0) ++answer;
    return;
  }
  for (int i = idx; i < num.size(); ++i) {
    func(num, i + 1, level + 1, sum + num[i]);
  }
}

int solution(vector<int> number) {
  func(number, 0, 0, 0);

  return answer;
}