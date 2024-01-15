#include <string>
#include <vector>

using namespace std;
vector<vector<int>> answer;

void hanoi(int n, int start, int end, int sub) {
  if (n == 1) {
    answer.push_back({start, end});
    return;
  }
  hanoi(n - 1, start, sub, end);
  answer.push_back({start, end});
  hanoi(n - 1, sub, end, start);
}

vector<vector<int>> solution(int n) {
  hanoi(n, 1, 3, 2);

  return answer;
}