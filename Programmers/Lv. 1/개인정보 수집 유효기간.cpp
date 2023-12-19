#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 2. 날짜 정수값으로 변환하는 함수 생성
int func(string date, int n) {
  int year = stoi(date.substr(0, 4));
  int month = stoi(date.substr(5, 2));
  int day = stoi(date.substr(8, 2));

  if (n > 0) {
    // 만약 나누어 떨어지면 month가 12월이 된것이다.
    // 그래서 (month + n)/12 연산에서 1을 빼줘야된다. 24/12 = 2 : x
    if ((month + n) % 12 == 0) {
      year += (month + n) / 12;
      --year;
      month = 12;
    } else {
      year += (month + n) / 12;
      month = (month + n) % 12;
    }
  }

  return year * 365 + (month - 1) * 28 + day;
}

vector<int> solution(string today, vector<string> terms,
                     vector<string> privacies) {
  vector<int> answer;

  // 1. terms 분리 및 데이터 저장
  int dat[100] = {0};
  for (int i = 0; i < terms.size(); ++i) {
    char alpha = terms[i][0];
    string limit = terms[i].substr(2);
    dat[alpha] = stoi(limit);
  }

  int curdate = func(today, 0);  // 3. 현재 날짜 일수로 계산

  for (int p = 0; p < privacies.size(); ++p) {
    // 4. 약관과 날짜 분리
    char alpha = privacies[p][privacies[p].length() - 1];
    string date = privacies[p].substr(0, privacies[p].length() - 2);

    int pri = func(date, dat[alpha]);  // 5. 계약 날짜 일수로 계산

    if (curdate >= pri) answer.push_back(p + 1);  // 6. 비교
  }

  return answer;
}