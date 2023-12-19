#include <iostream>

using namespace std;

int main(int argc, char** argv) {
  long long k, p, n;
  cin >> k >> p >> n;

  long long result = k;

  while (n--) {
    result = (result * p) % 1000000007;
  }
  cout << result;

  return 0;
}