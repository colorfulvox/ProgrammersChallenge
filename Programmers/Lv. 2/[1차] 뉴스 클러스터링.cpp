#include <map>
#include <string>

using namespace std;

struct info {
  int a;
  int b;
};

int solution(string str1, string str2) {
  int answer = 0;

  map<string, info> table;

  for (int s = 0; s < str1.length() - 1; ++s) {
    string tm = "";
    tm += str1[s];
    tm += str1[s + 1];

    bool flag = true;
    for (int t = 0; t < 2; ++t) {
      if (tm[t] >= 'A' && tm[t] <= 'Z')
        continue;
      else if (tm[t] >= 'a' && tm[t] <= 'z') {
        tm[t] = tm[t] - 'a' + 'A';
      } else {
        flag = false;
        break;
      }
    }
    if (flag) {
      if (table.find(tm) == table.end()) table[tm] = {0, 0};
      table[tm].a++;
    }
  }

  for (int s = 0; s < str2.length() - 1; ++s) {
    string tm = "";
    tm += str2[s];
    tm += str2[s + 1];

    bool flag = true;
    for (int t = 0; t < 2; ++t) {
      if (tm[t] >= 'A' && tm[t] <= 'Z')
        continue;
      else if (tm[t] >= 'a' && tm[t] <= 'z') {
        tm[t] = tm[t] - 'a' + 'A';
      } else {
        flag = false;
        break;
      }
    }
    if (flag) {
      if (table.find(tm) == table.end()) table[tm] = {0, 0};
      table[tm].b++;
    }
  }

  double gu = 0;
  double hap = 0;

  for (auto tb : table) {
    info jaca = tb.second;
    if (jaca.a > jaca.b) {
      hap += jaca.a;
      gu += jaca.b;
    } else {
      hap += jaca.b;
      gu += jaca.a;
    }
  }

  if (hap == 0 && gu == 0)
    answer = 65536;
  else
    answer = gu / hap * 65536.0f;

  return answer;
}