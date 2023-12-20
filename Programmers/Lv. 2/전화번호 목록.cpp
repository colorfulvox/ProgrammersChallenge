#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct hashnode {
  hashnode *h[10];

  hashnode() {
    for (int i = 0; i < 10; ++i) h[i] = nullptr;
  }
};

bool addhash(hashnode *node, int num) {
  if (!node->h[num]) {
    node->h[num] = new hashnode;
    return true;
  }
  return false;
}

bool compare(string a, string b) { return a.length() > b.length(); }

bool solution(vector<string> phone_book) {
  bool answer = true;

  hashnode table[10];

  sort(phone_book.begin(), phone_book.end(), compare);

  for (int p = 0; p < phone_book.size(); ++p) {
    bool flag = true;
    string temp = phone_book[p];
    hashnode *cur = table;
    for (int t = 0; t < temp.length(); ++t) {
      int dig = temp[t] - '0';
      flag = addhash(cur, dig);
      cur = cur->h[dig];
    }
    if (!flag) {
      answer = false;
      break;
    }
  }

  return answer;
}