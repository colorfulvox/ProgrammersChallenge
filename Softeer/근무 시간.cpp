#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv) {
  int result = 0;

  for (int i = 0; i < 5; ++i) {
    string before = "";
    string after = "";

    cin >> before >> after;

    string a = "";
    string b = "";
    int aminute = 0;
    int bminute = 0;
    for (int idx = 0; idx < after.length(); ++idx) {
      if (after[idx] == ':') {
        aminute += (stoi(a) * 60);
        bminute += (stoi(b) * 60);
        a = "";
        b = "";
      } else {
        a += after[idx];
        b += before[idx];
      }
    }
    aminute += stoi(a);
    bminute += stoi(b);

    result += aminute - bminute;
  }

  cout << result;

  return 0;
}