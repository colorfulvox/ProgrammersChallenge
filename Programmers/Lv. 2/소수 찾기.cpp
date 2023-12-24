#include <string>
#include <vector>

using namespace std;
bool dat[10000000] = {false};
bool used[10000000] = {false};

bool visited[7] = {false};

string target;
int answer = 0;

void func(int level, string num) {
  if (num.length()) {
    int n = stoi(num);
    if (!used[n]) {
      used[n] = true;
      if (!dat[n]) ++answer;
    }
  }

  if (level == target.length()) return;

  for (int i = 0; i < target.length(); ++i) {
    if (!visited[i]) {
      visited[i] = true;
      func(level + 1, num + target[i]);
      visited[i] = false;
    }
  }
}

int solution(string numbers) {
  target = numbers;

  dat[0] = true;
  dat[1] = true;
  for (int i = 2; i < 10000000; ++i) {
    if (dat[i]) continue;
    for (int j = 2; i * j < 10000000; ++j) dat[i * j] = true;
  }

  func(0, "");

  return answer;
}