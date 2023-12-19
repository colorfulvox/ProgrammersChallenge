#include <iostream>
#include <vector>

using namespace std;

struct info {
  int len;
  int acc;
};

int main(int argc, char** argv) {
  int max = 0;
  int n, m;
  cin >> n >> m;

  vector<info> area;
  vector<info> check;

  for (int i = 0; i < n; ++i) {
    int len, acc;
    cin >> len >> acc;
    area.push_back({len, acc});
  }
  for (int i = 0; i < m; ++i) {
    int len, acc;
    cin >> len >> acc;
    check.push_back({len, acc});
  }

  int aidx = 0;
  int cidx = 0;

  while (aidx < area.size()) {
    if (area[aidx].len > check[cidx].len) {
      area[aidx].len -= check[cidx].len;

      if (check[cidx].acc > area[aidx].acc) {
        int acc = check[cidx].acc - area[aidx].acc;
        if (max < acc) max = acc;
      }

      ++cidx;
    } else if (area[aidx].len < check[cidx].len) {
      check[cidx].len -= area[aidx].len;

      if (check[cidx].acc > area[aidx].acc) {
        int acc = check[cidx].acc - area[aidx].acc;
        if (max < acc) max = acc;
      }

      ++aidx;
    } else {
      if (check[cidx].acc > area[aidx].acc) {
        int acc = check[cidx].acc - area[aidx].acc;
        if (max < acc) max = acc;
      }
      ++aidx;
      ++cidx;
    }
  }
  cout << max;

  return 0;
}