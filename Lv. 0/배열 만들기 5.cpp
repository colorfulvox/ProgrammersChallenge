#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> intStrs, int k, int s, int l) {
  vector<int> answer;

  for (auto in = intStrs.begin(); in < intStrs.end(); ++in) {
    int temp = stoi(in->substr(s, l));
    if (temp > k) answer.push_back(temp);
  }

  return answer;
}