#include <iostream>
#include <string>
using namespace std;

bool solution(string s) {
  bool answer = true;
  int p = 0;
  int y = 0;

  for (auto str = s.begin(); str < s.end(); ++str) {
    if (*str == 'P' || *str == 'p')
      ++p;
    else if (*str == 'Y' || *str == 'y')
      ++y;
  }

  if (y != p) answer = false;

  return answer;
}