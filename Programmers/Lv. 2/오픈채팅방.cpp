#include <map>
#include <string>
#include <vector>

using namespace std;

struct info {
  string action;
  string uid;
};

vector<string> solution(vector<string> record) {
  vector<string> answer;

  map<string, string> user;
  // 업데이트되는 name을 저장히기 위한 map
  // uid가 key, name이 value

  vector<info> table;
  // uid에 따른 Enter, Leave를 구별

  for (int r = 0; r < record.size(); ++r) {
    string rec = record[r];

    // 띄어씌기를 기준으로 문장 저장
    vector<string> dat;
    size_t start = 0, end = 0;
    while ((end = rec.find(' ', start)) != string::npos) {
      dat.push_back(rec.substr(start, end - start));
      start = end + 1;
    }
    dat.push_back(rec.substr(start));

    if (dat[0] == "Enter") {
      user[dat[1]] = dat[2];
      table.push_back({dat[0], dat[1]});
    } else if (dat[0] == "Leave") {
      table.push_back({dat[0], dat[1]});
    } else {
      user[dat[1]] = dat[2];
    }
  }

  for (int t = 0; t < table.size(); ++t) {
    info temp = table[t];
    string name = user[temp.uid];

    if (temp.action == "Enter") {
      answer.push_back(name + "님이 들어왔습니다.");
    } else {
      answer.push_back(name + "님이 나갔습니다.");
    }
  }

  return answer;
}