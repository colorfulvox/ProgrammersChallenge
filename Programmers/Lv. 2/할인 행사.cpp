#include <map>
#include <string>
#include <vector>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
  int answer = 0;

  map<string, int> table;
  int max = 0;

  for (int i = 0; i < want.size(); ++i) {
    table[want[i]] = number[i];
    max += number[i];
  }

  for (int i = 0; i < discount.size(); ++i) {
    if (i + 10 <= discount.size()) {
      vector<string> temp =
          vector<string>(discount.begin() + i, discount.begin() + i + 10);
      map<string, int> tmtable = map<string, int>(table.begin(), table.end());
      int cnt = max;

      for (int t = 0; t < temp.size(); ++t) {
        if (tmtable.find(temp[t]) != tmtable.end()) {
          if (tmtable[temp[t]] > 0) {
            tmtable[temp[t]]--;
            cnt--;
          }
        }
      }
      if (cnt == 0) ++answer;
    }
  }

  return answer;
}