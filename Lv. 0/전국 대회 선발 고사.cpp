#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class info {
 public:
  int rank;
  int idx;
  info(int _rank, int _idx) : idx(_idx), rank(_rank) {}
};

bool compare(info a, info b) { return a.rank < b.rank; }

int solution(vector<int> rank, vector<bool> attendance) {
  int answer = 0;

  vector<info> posrank;

  for (int i = 0; i < rank.size(); ++i) {
    if (attendance[i]) posrank.push_back(info(rank[i], i));
  }
  sort(posrank.begin(), posrank.end(), compare);

  answer = 10000 * posrank[0].idx + 100 * posrank[1].idx + posrank[2].idx;

  return answer;
}