#include <iostream>
using namespace std;

// 각 행별로 가장 큰 수를 구한다.
// 3개의 행을 기준으로 a, b, c 경우의 수를 만든다.
// 어차피 나머지는 가장 큰수를 구한 ctable에 있으니 3개를 제외한
// 나머지 최대값 수는 ctable에서 불러온다.

int main(int argc, char** argv) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int test_case;
  int T;

  cin >> T;

  for (test_case = 1; test_case <= T; ++test_case) {
    int n;
    cin >> n;

    int** table = new int*[n];
    int* ctable = new int[n]();
    bool* used = new bool[n]();

    int ans = 0;
    int total = 0;

    for (int r = 0; r < n; ++r) {
      table[r] = new int[3]();
      int MAX = 0;
      for (int c = 0; c < 3; ++c) {
        cin >> table[r][c];
        if (table[r][c] > MAX) MAX = table[r][c];
        total += table[r][c];
      }
      ctable[r] = MAX;
    }

    if (n < 3)
      cout << "#" << test_case << " " << -1 << "\n";
    else {
      for (int f = 0; f < n; ++f) {
        used[f] = true;
        for (int s = 0; s < n; ++s) {
          if (used[s]) continue;
          used[s] = true;
          for (int t = 0; t < n; ++t) {
            if (used[t]) continue;
            used[t] = true;

            int sum = table[f][0] + table[s][1] + table[t][2];
            for (int c = 0; c < n; ++c) {
              if (used[c]) continue;
              sum += ctable[c];
            }
            if (ans < sum) ans = sum;

            used[t] = false;
          }
          used[s] = false;
        }
        used[f] = false;
      }
      cout << "#" << test_case << " " << total - ans << "\n";
    }
  }
  return 0;
}