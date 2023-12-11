#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class scor {
 public:
  double aver;
  int idx;
  scor(double _aver, int _idx) : aver(_aver), idx(_idx) {}
};

bool compare(scor a, scor b) { return a.aver > b.aver; }

vector<int> solution(vector<vector<int>> score) {
  vector<int> answer(score.size(), 0);

  vector<scor> table;

  for (int i = 0; i < score.size(); ++i) {
    table.push_back(
        scor(((double)score[i][0] + (double)score[i][1]) / 2.0f, i));
  }

  sort(table.begin(), table.end(), compare);
  int grade = 1;
  for (int i = 0; i < table.size(); ++i) {
    if (i > 0 && table[i].aver == table[i - 1].aver) {
      answer[table[i].idx] = answer[table[i - 1].idx];
      grade++;
    } else
      answer[table[i].idx] = grade++;
  }

  return answer;
}