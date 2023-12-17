/*
각 알바펫별 현재 위치를 저장하는 loc배열을 생성 (처음은 -1로 초기화)
문자열을 순회하며 만약 -1이면 최초로 현재 위치를 저장
만약 -1이 아니면 저장된 위치와 현재위치 차이 계산한뒤 현재 위치를 loc에 저장
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
  vector<int> answer;

  vector<int> loc(200, -1);

  for (int i = 0; i < s.length(); ++i) {
    if (loc[s[i]] == -1) {
      loc[s[i]] = i;
      answer.push_back(-1);
    } else {
      answer.push_back(i - loc[s[i]]);
      loc[s[i]] = i;
    }
  }

  return answer;
}