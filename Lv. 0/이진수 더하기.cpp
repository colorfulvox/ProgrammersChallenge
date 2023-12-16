#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

string solution(string bin1, string bin2) {
  string answer = "";

  int bi1 = 0;
  int bi2 = 0;

  int dep = 0;
  for (auto b1 = bin1.end() - 1; b1 >= bin1.begin(); --b1) {
    if (*b1 == '1') bi1 += pow(2, dep);
    ++dep;
  }
  dep = 0;
  for (auto b2 = bin2.end() - 1; b2 >= bin2.begin(); --b2) {
    if (*b2 == '1') bi2 += pow(2, dep);
    ++dep;
  }
  int result = bi1 + bi2;
  if (result == 0) answer = "0";
  while (result) {
    int num = result % 2;
    if (num == 0)
      answer += '0';
    else
      answer += '1';
    result /= 2;
  }
  reverse(answer.begin(), answer.end());

  return answer;
}