/*
1. 에라토스테네스의 체를 활용해 소수가 아닌 수들을 모두 제외한다. (bool pri)
2. 브루트포스 방식으로 3개를 중복 선택하지 않는 경우의 수들을 더해간뒤 소수인지
판단한다.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<bool> pri(3001, false);
int answer = 0;

void func(vector<int> nums, int level, int idx, int sum) {
  if (level == 3) {
    if (!pri[sum]) ++answer;
    return;
  }

  for (int i = idx; i < nums.size(); ++i) {
    func(nums, level + 1, i + 1, nums[i] + sum);
  }
}

int solution(vector<int> nums) {
  for (int i = 2; i < 3001; ++i) {
    if (pri[i]) continue;
    for (int j = 2; j < 3001; ++j) {
      if (i * j > 3000) break;
      pri[i * j] = true;
    }
  }

  func(nums, 0, 0, 0);

  return answer;
}