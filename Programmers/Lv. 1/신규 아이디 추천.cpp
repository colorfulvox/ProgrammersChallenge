#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
  string answer = "";

  for (int i = 0; i < new_id.length(); ++i) {
    char id = new_id[i];
    if (id >= 'A' && id <= 'Z') answer += id - 'A' + 'a';
    if (id == '.') {
      if (answer.length() == 0) continue;
      if (answer[answer.length() - 1] == '.') continue;
      answer += '.';
    }
    if (id != '-' && id != '_' && (id < 'a' || id > 'z') &&
        (id < '0' || id > '9'))
      continue;
    answer += id;
  }
  if (answer.length() == 0) {
    answer = "aaa";
  } else if (answer.length() <= 3) {
    int last = answer.length() - 1;
    while (true) {
      if (answer.length() == 0) {
        answer = "aaa";
        break;
      }
      if (answer[last] == '.') {
        answer = answer.substr(0, answer.length() - 1);
        last = answer.length() - 1;
      } else
        break;
    }
    if (answer.length() < 3) {
      char temp = answer[answer.length() - 1];
      while (answer.length() < 3) answer += temp;
    }
  } else if (answer.length() >= 16)
    answer = answer.substr(0, 15);

  int last = answer.length() - 1;
  while (true) {
    if (answer.length() == 0) {
      answer = "aaa";
      break;
    }
    if (answer[last] == '.') {
      answer = answer.substr(0, answer.length() - 1);
      last = answer.length() - 1;
    } else
      break;
  }

  return answer;
}