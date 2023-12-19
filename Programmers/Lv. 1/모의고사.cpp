#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
  vector<int> answer;

  vector<int> score(3, 0);
  int amax = 0;

  vector<vector<int>> table;
  table.push_back({1, 2, 3, 4, 5});
  table.push_back({2, 1, 2, 3, 2, 4, 2, 5});
  table.push_back({3, 3, 1, 1, 2, 2, 4, 4, 5, 5});
  int a1 = 0;
  int a2 = 0;
  int a3 = 0;

  for (int i = 0; i < answers.size(); ++i) {
    if (table[0][a1++] == answers[i]) {
      score[0]++;
      if (score[0] > amax) amax = score[0];
    }
    if (table[1][a2++] == answers[i]) {
      score[1]++;
      if (score[1] > amax) amax = score[1];
    }
    if (table[2][a3++] == answers[i]) {
      score[2]++;
      if (score[2] > amax) amax = score[2];
    }
    if (a1 >= table[0].size()) a1 = 0;
    if (a2 >= table[1].size()) a2 = 0;
    if (a3 >= table[2].size()) a3 = 0;
  }
  for (int i = 0; i < score.size(); ++i) {
    if (amax == score[i]) answer.push_back(i + 1);
  }

  return answer;
}