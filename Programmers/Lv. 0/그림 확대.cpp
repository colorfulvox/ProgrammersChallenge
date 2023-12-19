#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> picture, int k) {
  vector<string> answer;

  for (int i = 0; i < picture.size(); ++i) {
    string pic = picture[i];
    string temp = "";
    for (int p = 0; p < pic.length(); ++p) {
      for (int t = 0; t < k; ++t) temp += pic[p];
    }
    for (int t = 0; t < k; ++t) answer.push_back(temp);
  }

  return answer;
}