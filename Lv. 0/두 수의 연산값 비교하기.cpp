#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
  int answer = 0;

  int str = stoi(to_string(a) + to_string(b));
  int num = 2 * a * b;

  if (str > num)
    answer = str;
  else
    answer = num;

  return answer;
}