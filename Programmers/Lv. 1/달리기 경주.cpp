/*
1. Map에 각 선수들의 이름 (키)과 인덱스를 저장한다.
2. callings를 순회하면서 해당 이름이 불린 선수의 인덱스를 Map에서 가져온다.
3. 바로 앞에 선수의 이름을 players에서 가져온다.
4. Map과 Players를 업데이트한다. (불린 선수와 앞의 선수의 순서를 바꾼다.)
*/

#include <map>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
  vector<string> answer;

  map<string, int> plr;

  for (int i = 0; i < players.size(); ++i) plr[players[i]] = i;

  for (auto call = callings.begin(); call < callings.end(); ++call) {
    int idx = plr[*call];
    string target = players[idx - 1];

    plr[*call] = idx - 1;
    plr[target] = idx;

    string temp = target;
    players[idx - 1] = *call;
    players[idx] = target;
  }
  answer = players;

  return answer;
}