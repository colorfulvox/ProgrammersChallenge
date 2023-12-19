#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
  int answer = 0;
  int gop = 1;
  int hap = 0;

  for (auto num = num_list.begin(); num < num_list.end(); ++num) {
    gop *= *num;
    hap += *num;
  }
  if (gop < hap * hap) answer = 1;

  return answer;
}