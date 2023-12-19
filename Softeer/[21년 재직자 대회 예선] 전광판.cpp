#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv) {
  //  [0]
  //[1]  [2]
  //   [3]
  //[4]  [5]
  //   [6]
  vector<vector<bool>> number = {
      {true, true, true, false, true, true, true},      // 0
      {false, false, true, false, false, true, false},  // 1
      {true, false, true, true, true, false, true},     // 2
      {true, false, true, true, false, true, true},     // 3
      {false, true, true, true, false, true, false},    // 4
      {true, true, false, true, false, true, true},     // 5
      {true, true, false, true, true, true, true},      // 6
      {true, true, true, false, false, true, false},    // 7
      {true, true, true, true, true, true, true},       // 8
      {true, true, true, true, false, true, true}       // 9
  };

  int T;
  cin >> T;

  while (T--) {
    int cnt = 0;
    int a, b;
    cin >> a >> b;
    if (a > b) {
      int temp = a;
      a = b;
      b = temp;
    }

    while (a) {
      int adig = a % 10;
      int bdig = b % 10;
      a /= 10;
      b /= 10;
      if (adig == bdig) continue;

      for (int i = 0; i < 7; ++i) {
        if (number[adig][i] != number[bdig][i]) ++cnt;
      }
    }

    while (b) {
      int bdig = b % 10;
      b /= 10;
      for (int i = 0; i < 7; ++i) {
        if (number[bdig][i]) ++cnt;
      }
    }
    cout << cnt << endl;
  }

  return 0;
}