#include <map>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
  vector<int> answer;

  map<string, vector<string>> table;  // 누구를 신고했는지 저장하는 map
  map<string, int> count;             // 신고당한 횟수를 저장하는 map

  for (int i = 0; i < id_list.size(); ++i) {  // map 초기화
    table[id_list[i]] = {};
    count[id_list[i]] = 0;
  }

  for (int i = 0; i < report.size(); ++i) {
    string temp = report[i];  // report 파싱을 위한 변수

    string order = "";   // 신고한 사람
    string target = "";  // 신고 당한 사람

    for (int t = 0; t < temp.length(); ++t) {  // 파싱
      if (temp[t] == ' ') {
        target = temp.substr(t + 1);
        break;
      } else
        order += temp[t];
    }

    bool flag = true;
    for (int t = 0; t < table[order].size(); ++t)  // 이미 신고했는지 검사
    {
      if (target == table[order][t]) {
        flag = false;
        break;
      }
    }

    if (flag) {  // 신고를 안했다면 table map의 order에 target을 추가, count의
                 // target을 증가
      table[order].push_back(target);
      count[target]++;
    }
  }

  // id_list 순서로 table map의 order에 저장된 신고한 사람 검출
  // 실제로 신고한 사람이 k를 넘는지 count에서 확인해 검사한 후 조건이 맞으면
  // 이용 정지로 판단
  for (int i = 0; i < id_list.size(); ++i) {
    int cnt = 0;

    string order = id_list[i];

    for (int t = 0; t < table[order].size(); ++t) {
      string target = table[order][t];
      if (count[target] >= k) ++cnt;
    }

    answer.push_back(cnt);
  }

  return answer;
}