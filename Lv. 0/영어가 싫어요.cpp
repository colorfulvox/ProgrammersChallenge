#include <algorithm>
#include <string>
#include <vector>

using namespace std;

long long solution(string numbers) {
  long long answer = 0;
  long long dig = 1;

  string temp = "";
  for (auto str = numbers.end() - 1; str >= numbers.begin(); --str) {
    temp += *str;
    string retemp = temp;
    reverse(retemp.begin(), retemp.end());
    if (retemp == "zero") {
      dig *= 10;
      temp = "";
    } else if (retemp == "one") {
      answer += dig * 1;
      temp = "";
      dig *= 10;

    } else if (retemp == "two") {
      answer += dig * 2;
      temp = "";
      dig *= 10;
    } else if (retemp == "three") {
      answer += dig * 3;
      temp = "";
      dig *= 10;
    } else if (retemp == "four") {
      answer += dig * 4;
      temp = "";
      dig *= 10;
    } else if (retemp == "five") {
      answer += dig * 5;
      temp = "";
      dig *= 10;
    } else if (retemp == "six") {
      answer += dig * 6;
      temp = "";
      dig *= 10;
    } else if (retemp == "seven") {
      answer += dig * 7;
      temp = "";
      dig *= 10;
    } else if (retemp == "eight") {
      answer += dig * 8;
      temp = "";
      dig *= 10;
    } else if (retemp == "nine") {
      answer += dig * 9;
      temp = "";
      dig *= 10;
    }
  }

  return answer;
}