#include <string>
#include <vector>

using namespace std;

int answer = 0;
bool flag = true;

char table[5] = {'A', 'E', 'I', 'O', 'U'};

void func(int level, string temp, string word) {
  if (temp == word) flag = false;
  if (level == 5) return;

  for (int i = 0; i < 5; ++i) {
    if (flag) ++answer;
    func(level + 1, temp + table[i], word);
  }
}

int solution(string word) {
  func(0, "", word);
  return answer;
}