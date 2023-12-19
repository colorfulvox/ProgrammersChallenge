#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
  int n, m;
  cin >> n >> m;

  vector<string> roomtable;

  map<string, vector<bool>> room;

  for (int i = 0; i < n; ++i) {
    string temp;
    cin >> temp;
    roomtable.push_back(temp);
    room[temp] = vector<bool>(19, false);
  }

  while (m--) {
    string temp;
    int be;
    int af;
    cin >> temp >> be >> af;

    for (; be < af; ++be) room[temp][be] = true;
  }
  sort(roomtable.begin(), roomtable.end());
  map<string, vector<string>> result;

  for (int i = 0; i < roomtable.size(); ++i) {
    string target = roomtable[i];
    int t = 9;
    while (t < 18) {
      if (!room[target][t]) {
        int be = t;

        while (!room[target][t]) {
          ++t;
          if (t > 18) break;
        }
        int af;
        if (t > 18)
          af = 18;
        else
          af = t;

        if (be == 9)
          result[target].push_back("09-" + to_string(af));
        else
          result[target].push_back(to_string(be) + '-' + to_string(af));
      } else
        ++t;
    }
  }

  for (int i = 0; i < roomtable.size(); ++i) {
    string target = roomtable[i];
    cout << "Room " << target << ":" << endl;
    if (result[target].size() == 0)
      cout << "Not available" << endl;
    else {
      cout << result[target].size() << " available:" << endl;
      for (int t = 0; t < result[target].size(); ++t) {
        cout << result[target][t] << endl;
      }
    }
    if (i + 1 < roomtable.size()) cout << "-----" << endl;
  }

  return 0;
}