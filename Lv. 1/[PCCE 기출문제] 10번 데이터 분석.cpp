#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class info {
 public:
  int code;
  int date;
  int maximum;
  int remain;
  info(int _code, int _date, int _maximum, int _remain)
      : code(_code), date(_date), maximum(_maximum), remain(_remain) {}
};

auto compare = [](info a, info b, int cmd) {
  if (cmd == 0) return a.code < b.code;
  if (cmd == 1) return a.date < b.date;
  if (cmd == 2) return a.maximum < b.maximum;
  if (cmd == 3) return a.remain < b.remain;
};

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext,
                             string sort_by) {
  vector<vector<int>> answer;

  vector<info> table;

  int choice;
  if (ext == "code") choice = 0;
  if (ext == "date") choice = 1;
  if (ext == "maximum") choice = 2;
  if (ext == "remain") choice = 3;

  for (int i = 0; i < data.size(); ++i) {
    if (val_ext >= data[i][choice])
      table.push_back(info(data[i][0], data[i][1], data[i][2], data[i][3]));
  }

  if (sort_by == "code") choice = 0;
  if (sort_by == "date") choice = 1;
  if (sort_by == "maximum") choice = 2;
  if (sort_by == "remain") choice = 3;

  sort(table.begin(), table.end(),
       [&](info a, info b) { return compare(a, b, choice); });

  for (int t = 0; t < table.size(); ++t) {
    answer.push_back(
        {table[t].code, table[t].date, table[t].maximum, table[t].remain});
  }

  return answer;
}