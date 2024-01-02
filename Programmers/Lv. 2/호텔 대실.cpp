/*
[["15:00", "17:00"], ["16:40", "18:20"], ["14:20", "15:20"],
["14:10", "19:20"],  ["18:20", "21:20"]]

시작 시간을 기준으로 오름차순으로 정렬한다.

["14:10", "19:20"]
["14:20", "15:20"]
["15:00", "17:00"]
["16:40", "18:20"]
["18:20", "21:20"]

여기서 중요한것은 시작 시간 순으로 정렬했다는것은
못해도 다음 시작 시간은 전 시작 시간 이후라는 것이다.
그래서 결국은 종료 시간을 각 room에 저장하고
각 room중에서 가장 빠른 종료 시간 and 현재 시작 시간보다
작거나 같은 종료 시간을 고르면 된다.

예시)

1. ["14:10", "19:20"]
현재 room이 없으니 새 room을 생성해 종료 시간을 저장한다.
청소시간이 있으니 10분을 더해준다. 19:20 -> 19:30

Room  [0]
     19:30

2. ["14:20", "15:20"]
현재 [0] Room이 있지만 시작 시간이 [0] room의 종료 시간보다 작다.
새 room을 생성한다.

Room  [0]    [1]
     19:30  15:30

3. ["15:00", "17:00"]
두개중에 시작 시간보다 작거나 같은 종료시간이 없다.
새 Room을 생성한다.

Room  [0]    [1]    [2]
     19:30  15:30  17:10

4. ["16:40", "18:20"]
[1] Room의 종료시간이 시작 시간보다 작다.
다른 종료 시간들은 모두 크기에 [1] Room의 시간을 업데이트 한다.

Room  [0]    [1]    [2]
     19:30  18:30  17:10

5. ["18:20", "21:20"]
[2] Room의 종료 시간이 시작 시간보다 작다.

Room  [0]    [1]    [2]
     19:30  18:30  21:30

결국 답은 Room의 사이즈 크기가 된다.
answer = 3
*/

#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool cmp(vector<string> a, vector<string> b) {
  string a_b = a[0];
  string b_b = b[0];

  int a_h = stoi(a_b.substr(0, 2));
  int a_m = stoi(a_b.substr(3));

  int b_h = stoi(b_b.substr(0, 2));
  int b_m = stoi(b_b.substr(3));

  if (a_h == b_h)
    return a_m < b_m;
  else
    return a_h < b_h;
}

int solution(vector<vector<string>> book_time) {
  int answer = 0;

  sort(book_time.begin(), book_time.end(), cmp);

  vector<int> room;

  for (auto book = book_time.begin(); book < book_time.end(); ++book) {
    auto temp = *book;

    int bf_h = stoi(temp[0].substr(0, 2)) * 60;
    int bf_m = stoi(temp[0].substr(3));
    int bf_time = bf_h + bf_m;

    int af_h = stoi(temp[1].substr(0, 2)) * 60;
    int af_m = stoi(temp[1].substr(3));
    int af_time = af_h + af_m + 10;

    if (room.size() > 0) {
      int idx = -1;
      int timemax = 1441;
      for (int r = 0; r < room.size(); ++r) {
        if (timemax > room[r] && room[r] <= bf_time) {
          timemax = room[r];
          idx = r;
        }
      }
      if (idx == -1)
        room.push_back(af_time);
      else {
        room[idx] = af_time;
      }

    } else
      room.push_back(af_time);
  }
  answer = room.size();

  return answer;
}