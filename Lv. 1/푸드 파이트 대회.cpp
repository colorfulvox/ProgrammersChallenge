#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
  string answer = "";

  for (int i = 1; i < food.size(); ++i) {
    int cnt = food[i] / 2;
    while (cnt--) answer += (i + '0');
  }
  string temp = answer;
  reverse(temp.begin(), temp.end());
  answer += '0' + temp;

  return answer;
}