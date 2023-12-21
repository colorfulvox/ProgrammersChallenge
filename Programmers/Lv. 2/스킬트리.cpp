#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
  int answer = 0;

  vector<bool> check(100, false);  // 스킬에 속하는지 확인하는 check 배열

  for (int i = 0; i < skill.length(); ++i) check[skill[i]] = true;

  for (int s = 0; s < skill_trees.size(); ++s) {
    string temp = skill_trees[s];
    int sidx = 0;  // 현재 스킬트리 idx
    bool flag = true;
    for (int t = 0; t < temp.length(); ++t) {
      if (check[temp[t]])  // 만약 스킬트리에 문자이면 검사
      {
        if (temp[t] == skill[sidx])  // 현재 스킬트리와 지금 스킬과 같으면,
          ++sidx;
        else {
          flag = false;
          break;
        }
      }
    }
    if (flag) ++answer;
  }

  return answer;
}