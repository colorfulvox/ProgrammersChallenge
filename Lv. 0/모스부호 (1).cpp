#include <map>
#include <string>
#include <vector>

using namespace std;

string solution(string letter) {
  map<string, char> morse = {
      {".-", 'a'},   {"-...", 'b'}, {"-.-.", 'c'}, {"-..", 'd'},  {".", 'e'},
      {"..-.", 'f'}, {"--.", 'g'},  {"....", 'h'}, {"..", 'i'},   {".---", 'j'},
      {"-.-", 'k'},  {".-..", 'l'}, {"--", 'm'},   {"-.", 'n'},   {"---", 'o'},
      {".--.", 'p'}, {"--.-", 'q'}, {".-.", 'r'},  {"...", 's'},  {"-", 't'},
      {"..-", 'u'},  {"...-", 'v'}, {".--", 'w'},  {"-..-", 'x'}, {"-.--", 'y'},
      {"--..", 'z'}};

  string answer = "";

  string temp = "";
  for (auto le = letter.begin(); le < letter.end(); ++le) {
    if (*le == ' ') {
      answer += morse[temp];
      temp = "";
    } else
      temp += *le;
  }
  answer += morse[temp];

  return answer;
}