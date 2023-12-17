/*
1. board에 각 열 별로 stack으로 저장한다.
2. moves의 idx값의 stack의 값을 뽑아 바구니에 저장한다.
3. 저장할때 만약 마지막 값과 같으면 answer를 증가시킨다.
*/

#include <stack>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
  int answer = 0;

  vector<stack<int>> table;

  vector<int> baguni;

  for (int c = 0; c < board[0].size(); ++c) {
    table.push_back(stack<int>());

    for (int r = board.size() - 1; r >= 0; --r) {
      if (board[r][c] == 0) break;
      table[c].push(board[r][c]);
    }
  }

  for (int i = 0; i < moves.size(); ++i) {
    int idx = moves[i] - 1;
    if (table[idx].size() > 0) {
      int item = table[idx].top();
      table[idx].pop();
      if (baguni.size() > 0) {
        if (baguni[baguni.size() - 1] == item) {
          answer += 2;
          baguni.pop_back();
        } else
          baguni.push_back(item);
      } else
        baguni.push_back(item);
    }
  }

  return answer;
}