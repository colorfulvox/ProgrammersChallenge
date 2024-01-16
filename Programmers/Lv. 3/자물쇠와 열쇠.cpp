#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> cycle(vector<vector<int>> key) {
  vector<vector<int>> temp(key.size(), vector<int>(key.size(), 0));
  int size = key.size();
  for (int c = size - 1; c >= 0; --c) {
    for (int r = 0; r < size; ++r) {
      temp[r][c] = key[size - 1 - c][r];
    }
  }

  return temp;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
  bool answer = false;

  int n = lock.size();
  int m = key.size();
  int size = n - 2 + 2 * m;
  vector<vector<int>> map(size, vector<int>(size, 0));

  int empty = 0;

  for (int r = m - 1, i = 0; r < size - m + 1; ++r) {
    for (int c = m - 1, j = 0; c < size - m + 1; ++c) {
      if (!lock[i][j]) {
        lock[i][j] = -1;
        ++empty;
      }
      map[r][c] = lock[i][j++];
    }
    ++i;
  }

  for (int r = 0; r <= size - m; r++) {
    for (int c = 0; c <= size - m; ++c) {
      int cy = 4;

      while (cy--) {
        // for(int i=0;i<m;++i)
        // {
        //     for(int j=0;j<m;++j)cout<<key[i][j]<<" ";
        //     cout<<endl;
        //  }
        // cout<<endl;

        // 회전
        bool flag = true;
        int cnt = empty;
        for (int i = 0, rs = r; i < m; ++i) {
          if (!flag) break;
          for (int j = 0, cs = c; j < m; ++j) {
            if (map[rs][cs] == 1 && key[i][j] == 1) {
              flag = false;
              break;
            }
            if (map[rs][cs] == -1 && key[i][j] == 1) --cnt;
            cs++;
          }
          rs++;
        }
        key = cycle(key);
        if (!flag) continue;
        if (cnt == 0) answer = true;
      }
      // cout<<"---------"<<endl;
    }
  }

  return answer;
}