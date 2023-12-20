#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

bool func(long long num) {
  for (long long i = 2; i <= sqrt(num); ++i) {
    if (num % i == 0) return false;
  }

  return true;
}

int solution(int n, int k) {
  int answer = 0;

  string temp = "";
  if (k != 10) {
    int num = n;
    while (num) {
      temp += ((num % k) + '0');
      num /= k;
    }
    reverse(temp.begin(), temp.end());
  } else
    temp = to_string(n);

  string sub = "";

  for (int t = 0; t < temp.length(); ++t) {
    if (temp[t] != '0')
      sub += temp[t];
    else {
      if (sub.length() > 0) {
        long long num = stol(sub);
        sub = "";

        if (num != 1 && func(num)) {
          ++answer;
        }
      }
    }
  }
  if (sub.length() > 0) {
    long long num = stol(sub);

    if (num != 1 && func(num)) ++answer;
  }

  return answer;
}