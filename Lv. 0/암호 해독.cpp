#include <string>
#include <vector>

using namespace std;

string solution(string cipher, int code) {
  string answer = "";

  for (auto ci = cipher.begin() + (code - 1); ci < cipher.end(); ci += (code))
    answer += *ci;
  return answer;
}