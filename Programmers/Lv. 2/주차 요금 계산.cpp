#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct info {
  int intime;  // 현재 들어온 시간
  int total;   // 주차장을 이용한 총 시간 (분 단위)
  bool check;  // 마지막에 나갔는지 판단 하기 위함
};

vector<int> solution(vector<int> fees, vector<string> records) {
  vector<int> answer;

  map<string, info> record;
  vector<string> table;  // 출력 순서를 위한 string table

  for (int r = 0; r < records.size(); ++r) {
    string rc = records[r];

    string hour = rc.substr(0, 2);
    string minute = rc.substr(3, 2);
    string number = rc.substr(6, 4);
    string cmd = rc.substr(11);

    int time = stoi(hour) * 60 + stoi(minute);  // 분으로 계산

    if (record.find(number) == record.end()) {
      record[number] = {0, 0, false};
      table.push_back(number);
    }
    if (cmd == "IN") {
      record[number].intime = time;
      record[number].check = true;
    } else {
      record[number].total += (time - record[number].intime);
      // 만약 Out이면 나간 시간 - 과거 들어온 시간 계산

      record[number].intime = 0;
      record[number].check = false;
    }
  }

  sort(table.begin(), table.end());

  int maxtime = (23 * 60) + 59;

  for (int t = 0; t < table.size(); ++t) {
    string temp = table[t];

    int pay = 0;

    if (record[temp].check)  // 안나간걸로 판단해서 maxtime과 intime의 차이 계산
      record[temp].total += (maxtime - record[temp].intime);

    int total = record[temp].total - fees[0];

    if (total <= 0)
      pay = fees[1];
    else {
      int subtime;
      if (total % fees[2] != 0)  // 나누어 떨어지지 않으면 +1 올림 추가
        subtime = total / fees[2] + 1;
      else
        subtime = total / fees[2];

      pay = fees[1] + (subtime * fees[3]);
    }
    answer.push_back(pay);
  }

  return answer;
}