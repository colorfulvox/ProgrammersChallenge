#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
  int m, n, k;
  cin >> m >> n >> k;

  vector<int> secret;
  vector<int> table;

  while (m--) {
    int num;
    cin >> num;
    secret.push_back(num);
  }

  while (n--) {
    int num;
    cin >> num;
    table.push_back(num);
  }

  for (int i = 0; i < table.size(); ++i) {
    if (i + secret.size() <= table.size()) {
      bool flag = true;
      vector<int> control =
          vector<int>(table.begin() + i, table.begin() + i + secret.size());

      for (int c = 0; c < control.size(); ++c) {
        if (control[c] != secret[c]) {
          flag = false;
          break;
        }
      }
      if (flag) {
        cout << "secret" << endl;
        return 0;
      }
    }
  }

  cout << "normal" << endl;
  return 0;
}