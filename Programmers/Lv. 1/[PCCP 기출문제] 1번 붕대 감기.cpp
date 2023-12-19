#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
  int answer = 0;

  int time = 1;
  int skill = 0;

  int a = 0;

  int max = health;

  while (true) {
    bool flag = true;

    if (attacks.size() <= a) break;

    if (time == attacks[a][0]) {
      health -= attacks[a][1];
      if (health <= 0) break;
      ++a;
      skill = 0;
      flag = false;
    }

    if (flag) {
      if (health + bandage[1] < max)
        health += bandage[1];
      else
        health = max;

      ++skill;

      if (skill == bandage[0]) {
        if (health + bandage[2] < max)
          health += bandage[2];
        else
          health = max;
        skill = 0;
      }
    }

    ++time;
  }
  if (health <= 0)
    answer = -1;
  else
    answer = health;

  return answer;
}