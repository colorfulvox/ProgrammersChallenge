#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
  vector<int> answer;

  for (int t = 0; t < targets.size(); ++t) {
    string tar = targets[t];
    int cnt = 0;
    for (int i = 0; i < tar.length(); ++i) {
      bool flag = false;
      int click = 21e8;
      for (int k = 0; k < keymap.size(); ++k) {
        string key = keymap[k];
        for (int j = 0; j < key.length(); ++j) {
          if (tar[i] == key[j]) {
            if (click > j + 1) {
              click = j + 1;
              flag = true;
            }
          }
        }
      }
      if (flag)
        cnt += click;
      else {
        cnt = -1;
        break;
      }
    }
    answer.push_back(cnt);
  }

  return answer;
}