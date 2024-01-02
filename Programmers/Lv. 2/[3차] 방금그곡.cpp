/*
C#, D#, F#, G#, A#은 G이휴 H문자부터 대체한다.

C# => 'C' - 'A' + 'H'
*/

#include <string>
#include <vector>

using namespace std;

string solution(string m, vector<string> musicinfos) {
  string answer = "";
  int len = -1;

  string mm = "";
  for (int i = 0; i < m.length(); ++i) {
    if (m[i] == 'E' || m[i] == 'B')
      mm += m[i];
    else {
      if (i + 1 < m.length()) {
        if (m[i + 1] == '#') {
          mm += (m[i] - 'A' + 'H');
          ++i;
        } else
          mm += m[i];
      } else
        mm += m[i];
    }
  }

  for (int s = 0; s < musicinfos.size(); ++s) {
    string temp = musicinfos[s];
    vector<string> dat;
    size_t start = 0, end = 0;
    while ((end = temp.find(',', start)) != string::npos) {
      dat.push_back(temp.substr(start, end - start));
      start = end + 1;
    }
    dat.push_back(temp.substr(start));

    int before = stoi(dat[0].substr(0, 2)) * 60 + stoi(dat[0].substr(3, 2));
    int after = stoi(dat[1].substr(0, 2)) * 60 + stoi(dat[1].substr(3, 2));

    string mus = dat[3];
    string sheet = "";
    int idx = 0;
    while (before < after) {
      if (mus[idx] == 'E' || mus[idx] == 'B')
        sheet += mus[idx];
      else {
        if (idx + 1 < mus.length()) {
          if (mus[idx + 1] == '#') {
            sheet += (mus[idx] - 'A' + 'H');
            ++idx;
          } else
            sheet += mus[idx];
        } else
          sheet += mus[idx];
      }

      ++idx;
      if (idx >= mus.length()) idx = 0;

      ++before;
    }

    if (sheet.find(mm) != string::npos) {
      if (len == -1) {
        answer = dat[2];
        len = sheet.length();
      } else if (len < sheet.length()) {
        answer = dat[2];
        len = sheet.length();
      }
    }
  }
  if (len == -1) answer = "(None)";

  return answer;
}