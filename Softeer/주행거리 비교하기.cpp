#include <iostream>
using namespace std;

int main(int argc, char** argv) {
  int a, b;
  cin >> a >> b;
  if (a == b)
    cout << "same";
  else if (a > b)
    cout << "A";
  else
    cout << "B";

  return 0;
}