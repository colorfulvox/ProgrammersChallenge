/*
시간 초과로 안되지만 연결리스트 방식

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<string, int> member;

struct Node {
  string name;

  vector<Node*> child;

  Node(string _name) { name = _name; }
};
int env;

Node* search(Node* parent, string target) {
  if (parent == nullptr) return nullptr;

  if (parent->name == target) return parent;

  for (auto ch : parent->child) {
    Node* result = search(ch, target);
    if (result != nullptr) return result;
  }
  return nullptr;
}

Node* dist(Node* parent, string target) {
  if (env == 0) return nullptr;

  if (parent == nullptr) return nullptr;

  if (parent->name == target) {
    int d = env / 10;

    member[target] += env - d;
    env = d;

    return parent;
  }

  for (auto ch : parent->child) {
    Node* result = dist(ch, target);
    if (result != nullptr) {
      int d = env / 10;

      member[parent->name] += env - d;
      env = d;

      return result;
    }
  }

  return nullptr;
}

vector<int> solution(vector<string> enroll, vector<string> referral,
                     vector<string> seller, vector<int> amount) {
  vector<int> answer;

  member["center"] = 0;
  for (auto en : enroll) member[en] = 0;

  Node* center = new Node("center");

  for (int i = 0; i < enroll.size(); ++i) {
    string refer = referral[i];
    string en = enroll[i];
    if (refer == "-")
      center->child.push_back(new Node(en));
    else {
      Node* node = search(center, refer);
      node->child.push_back(new Node(en));
    }
  }

  for (int i = 0; i < seller.size(); ++i) {
    string target = seller[i];
    env = amount[i] * 100;

    dist(center, target);
  }

  for (auto en : enroll) {
    answer.push_back(member[en]);
  }

  return answer;
}
*/

// hashmap 방식

#include <map>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral,
                     vector<string> seller, vector<int> amount) {
  vector<int> answer;

  map<string, int> memrev;
  map<string, string> member;
  member["center"] = "";

  for (int i = 0; i < enroll.size(); ++i) {
    string en = enroll[i];
    string re = referral[i];

    memrev[en] = 0;

    if (re == "-")
      member[en] = "center";
    else
      member[en] = re;
  }

  for (int i = 0; i < seller.size(); ++i) {
    string target = seller[i];
    int rev = amount[i] * 100;

    while (member[target] != "") {
      if (rev == 0) break;
      int drev = rev / 10;
      memrev[target] += rev - drev;
      rev /= 10;
      target = member[target];
    }
  }

  for (auto en : enroll) {
    answer.push_back(memrev[en]);
  }

  return answer;
}