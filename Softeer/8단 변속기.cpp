#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv) {
  string result;

  vector<int> dct;

  for (int i = 0; i < 8; ++i) {
    int cmd;
    cin >> cmd;
    if (dct.size() > 0 && abs(dct[dct.size() - 1] - cmd) != 1) {
      result = "mixed";
      break;
    }
    if (i == 0 && cmd == 1) result = "ascending";
    if (i == 0 && cmd == 8) result = "descending";
    dct.push_back(cmd);
  }

  cout << result;

  return 0;
}