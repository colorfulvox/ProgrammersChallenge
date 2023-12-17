/*
사실 브루트포스 방식으로 모든 경우의 수를 검사해야될것같은데
각 다른 종류를 선택하는 최대의 경우의 수를 구하는것이여서
dat에 각 번호별로 검사한것을 저장하고 answer값을 증가 시켰다.
하지만 n/2까지의 최대값이기에 만약 answer가 n/2보다 크면 n/2로 저장한다.
*/

#include <vector>
using namespace std;

int solution(vector<int> nums) {
  int answer = 0;

  int n = nums.size() / 2;

  bool dat[200001] = {false};
  for (int i = 0; i < nums.size(); ++i) {
    if (!dat[nums[i]]) {
      dat[nums[i]] = true;
      ++answer;
    }
  }
  if (answer > n) answer = n;

  return answer;
}