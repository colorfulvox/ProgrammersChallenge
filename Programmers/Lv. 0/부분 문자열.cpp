#include <string>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
  int answer = 0;

  for (int i = 0; i < str2.length(); ++i) {
    if (i + str1.length() <= str2.length()) {
      string temp = str2.substr(i, str1.length());
      if (temp == str1) answer = 1;
    }
  }

  return answer;
}