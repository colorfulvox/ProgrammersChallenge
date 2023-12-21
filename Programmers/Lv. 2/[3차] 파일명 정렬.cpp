/*
1. head를 key로 하고 각 head별로 99999까지의 string 배열을 저장하는
map을 생성한다.

2. 만약 map 해당하는 head가 없을 경우
lst에 head를 추가하고, string 배열 초기화를 한다.

3. map[head][num] 위치에 문자를 순서대로 저장한다.
map[IMG][0] : img1.png, IMG01.GIF

4. lst를 sort로 정렬한다.

5. lst 순서대로 map에 저장된 head의 0 - 99999까지 탐색하며
순서대로 answer에 저장한다.
*/

#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> files) {
  vector<string> answer;

  map<string, vector<vector<string>>> table;

  vector<string> lst;

  for (int f = 0; f < files.size(); ++f) {
    string temp = files[f];
    string num = "";
    string head = "";
    bool flag = false;

    for (int t = 0; t < temp.length(); ++t) {
      if (temp[t] >= '0' && temp[t] <= '9') {
        flag = true;
        num += temp[t];
      } else if (flag)
        break;
      else {
        if (temp[t] >= 'a' && temp[t] <= 'z')
          head += (temp[t] - 'a' + 'A');
        else
          head += temp[t];
      }
    }
    int n = stoi(num);

    if (table.find(head) == table.end()) {
      table[head] = vector<vector<string>>(100000);
      lst.push_back(head);
    }

    table[head][n].push_back(temp);
  }

  sort(lst.begin(), lst.end());

  for (int l = 0; l < lst.size(); ++l) {
    string head = lst[l];

    for (int h = 0; h < table[head].size(); ++h) {
      for (int i = 0; i < table[head][h].size(); ++i)
        answer.push_back(table[head][h][i]);
    }
  }

  return answer;
}