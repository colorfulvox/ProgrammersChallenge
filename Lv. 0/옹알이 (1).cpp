#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
  int answer = 0;

  for (auto babb = babbling.begin(); babb < babbling.end(); ++babb) {
    string temp = "";
    for (auto ba = babb->begin(); ba < babb->end(); ++ba) {
      temp += *ba;
      if (temp == "aya") temp = "";
      if (temp == "ye") temp = "";
      if (temp == "woo") temp = "";
      if (temp == "ma") temp = "";
    }
    if (!temp.length()) ++answer;
  }

  return answer;
}