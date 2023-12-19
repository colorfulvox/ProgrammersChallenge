#include <iostream>
#include <string>

using namespace std;

int main(void) {
  string str;
  cin >> str;

  for (auto st = str.begin(); st < str.end(); ++st) {
    if (*st >= 'A' && *st <= 'Z')
      *st = *st - 'A' + 'a';
    else
      *st = *st - 'a' + 'A';
  }
  cout << str;

  return 0;
}