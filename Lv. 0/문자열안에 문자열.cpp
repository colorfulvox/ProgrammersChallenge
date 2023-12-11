#include <string>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
  int answer = 2;
  for (int i = 0; i < str1.length() - str2.length() + 1; ++i) {
    string temp = str1.substr(i, str2.length());
    if (temp == str2) answer = 1;
  }

  return answer;
}