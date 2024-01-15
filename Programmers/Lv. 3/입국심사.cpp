#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
  sort(times.begin(), times.end());
  long long mintime = times[0];

  long long first = mintime;
  long long last = mintime * n;
  long long answer = mintime * n;

  while (first <= last) {
    long long mid = (first + last) / 2;

    long long MIN = 0;
    for (int t = 0; t < times.size(); ++t) {
      MIN += mid / times[t];

      if (MIN >= n) {
        answer = mid;
        last = mid - 1;
        break;
      }
    }
    if (MIN < n) first = mid + 1;
  }

  return answer;
}