#include <deque>
#include <string>
#include <vector>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
  int answer = 0;

  deque<string> dq;

  for (int i = 0; i < cities.size(); ++i) {
    if (cacheSize == 0) {
      answer += 5;
      continue;
    }
    string city = cities[i];
    for (int c = 0; c < city.length(); ++c) {
      if (city[c] >= 'A' && city[c] <= 'Z') city[c] = city[c] - 'A' + 'a';
    }

    if (dq.size() == 0) {
      answer += 5;
      dq.push_back(city);
    } else {
      deque<string> tm;

      int size = dq.size();
      bool flag = false;
      while (size--) {
        string temp = dq.front();
        dq.pop_front();
        if (city != temp)
          tm.push_back(temp);
        else
          flag = true;
      }

      if (flag) {
        answer += 1;
        tm.push_front(city);  // 맨 앞이 최신 위치
      } else {
        if (cacheSize == tm.size())
          tm.pop_back();  // 가장 오랫동안 참조되지 않은것을 뺀다.

        tm.push_front(city);  // 맨 앞이 최신 위치
        answer += 5;
      }
      dq = tm;
    }
  }

  return answer;
}