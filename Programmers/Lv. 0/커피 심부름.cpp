#include <string>
#include <vector>

using namespace std;

int solution(vector<string> order) {
  int answer = 0;

  for (auto ord = order.begin(); ord < order.end(); ++ord) {
    if (*ord == "icecafelatte" || *ord == "cafelatteice" ||
        *ord == "hotcafelatte" || *ord == "cafelattehot" || *ord == "cafelatte")
      answer += 5000;
    else
      answer += 4500;
  }

  return answer;
}