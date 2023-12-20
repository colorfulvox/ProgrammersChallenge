#include <string>
#include <vector>

using namespace std;

int cnt = 0;
int zero = 0;

string convert(string target) {
  int one = 0;
  for (auto tar = target.begin(); tar < target.end(); ++tar) {
    if (*tar == '1')
      ++one;
    else
      zero++;
  }

  ++cnt;
  if (one == 1) return "1";

  string temp = "";
  while (one) {
    temp += (one % 2) + '0';
    one /= 2;
  }

  return temp;
}

vector<int> solution(string s) {
  vector<int> answer;

  while (true) {
    if (s == "1") break;
    s = convert(s);
  }

  answer.push_back(cnt);
  answer.push_back(zero);
  return answer;
}