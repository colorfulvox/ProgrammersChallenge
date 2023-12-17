#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
  string answer = "";

  int date[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  int day = b - 1;  // 0이 금요일이다. 그래서 -1을 해주자. ex) 1월 1일
  for (int i = 1; i < a; ++i) {
    day += date[i];
  }

  string week[7] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};

  answer = week[day % 7];

  return answer;
}