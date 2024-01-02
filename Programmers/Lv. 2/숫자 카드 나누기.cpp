#include <iostream>
#include <string>
#include <vector>

using namespace std;

int GCD(int a, int b) {
  if (a < b) {
    int tm = a;
    a = b;
    b = tm;
  }

  int temp;
  while (a % b != 0) {
    temp = a % b;
    a = b;
    b = temp;
  }
  return b;
}

int LCM(int a, int b) { return (a * b) / GCD(a, b); }

int solution(vector<int> arrayA, vector<int> arrayB) {
  int answer = 0;

  int a = arrayA[0];
  for (int i = 1; i < arrayA.size(); ++i) {
    a = GCD(a, arrayA[i]);
  }

  int b = arrayB[0];
  for (int i = 1; i < arrayB.size(); ++i) {
    b = GCD(b, arrayB[i]);
  }

  bool bflag = true;
  bool aflag = true;

  for (int i = 0; i < arrayA.size(); ++i) {
    if (aflag) {
      if (arrayB[i] % a == 0) aflag = false;
    }
    if (bflag) {
      if (arrayA[i] % b == 0) bflag = false;
    }
  }
  if (bflag && aflag) {
    if (a > b)
      answer = a;
    else
      answer = b;
  } else if (bflag)
    answer = b;
  else if (aflag)
    answer = a;

  return answer;
}