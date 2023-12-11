#include <iostream>
#include <string>

using namespace std;

int main(void) {
  string str;
  cin >> str;

  for (auto word = str.begin(); word < str.end(); ++word) cout << *word << endl;

  return 0;
}