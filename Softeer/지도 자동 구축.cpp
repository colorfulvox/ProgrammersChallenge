#include <iostream>
using namespace std;

int main(int argc, char** argv) {
  int n;
  cin >> n;
  int m = 2;
  for (int i = 1; i < n; ++i) m = m + m - 1;

  cout << (m + m - 1) * (m + m - 1) << endl;
  return 0;
}