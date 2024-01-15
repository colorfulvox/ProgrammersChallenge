#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
  string answer = "";

  int ans = 0;

  vector<int> timetb;

  for (auto time : timetable) {
    int hour = stoi(time.substr(0, 2)) * 60;
    int min = stoi(time.substr(3, 2));
    timetb.push_back(hour + min);
  }
  sort(timetb.begin(), timetb.end());

  int time = 540;

  int idx = 0;
  int cnt = 0;

  while (n--) {
    for (; idx < timetb.size(); ++idx) {
      if (time >= timetb[idx])
        ++cnt;
      else
        break;
    }
    if (cnt < m) {
      cnt = 0;
      ans = time;
    } else {
      int lastidx = idx;
      if (cnt > m) {
        int mcnt = cnt;
        while (mcnt > m) {
          --lastidx;
          --mcnt;
        }
      }
      cnt = cnt - m;

      ans = timetb[lastidx - 1] - 1;
    }
    time += t;
  }
  int hour = ans / 60;
  int min = ans % 60;

  // cout<<hour<<" "<<min<<endl;
  if (hour >= 10)
    answer += to_string(hour);
  else {
    answer += '0';
    answer += to_string(hour);
  }
  answer += ':';
  if (min >= 10)
    answer += to_string(min);
  else {
    answer += '0';
    answer += to_string(min);
  }

  return answer;
}