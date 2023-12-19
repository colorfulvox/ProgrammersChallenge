#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
  string answer = "";

  int score[100] = {0};
  for (int i = 0; i < survey.size(); ++i) {
    char t1 = survey[i][0];
    char t2 = survey[i][1];
    if (choices[i] == 4)
      continue;
    else if (choices[i] < 4)
      score[t1] += 4 - choices[i];
    else
      score[t2] += choices[i] - 4;
  }

  if (score['R'] < score['T'])
    answer += 'T';
  else
    answer += 'R';
  if (score['C'] < score['F'])
    answer += 'F';
  else
    answer += 'C';
  if (score['J'] < score['M'])
    answer += 'M';
  else
    answer += 'J';
  if (score['A'] < score['N'])
    answer += 'N';
  else
    answer += 'A';

  return answer;
}