// Union-Find : 합집합 찾기(서로소 집합 알고리즘)
// 두개의 노드를 선택해서 현재 이 노드가 서로 같은 그래프에 속하는지 판별한다.

// 기본적으로 모든 노드가 연결되지 않았다고 가정하면

// [1 2 3 4 5]
//  1 2 3 4 5 : 부모 노드 번호
// 각 노드는 자기 자신을 가리키게 한다. [1] : 1, [2] : 2

// 그리고 1과 2를 연결할때 번호중에 가장 작은 번호를 부모 노드로 설정한다.
// [1 2 3 4 5]
//  1 1 3 4 5
// 이런 방식으로 1과 2가 연결되었다고 판단하게 된다.

// 현재 상황에서 2와 3이 연결되면
// [1 2 3 4 5]
//  1 1 2 4 5
// [3]이 2가 될것이다.
// 하지만 문제는 1과 2는 연결 되었지만, 1과 3이 연결되었는지는 판단할 수가 없다.
// 그래서 재귀 함수를 활용해 3의 실.제 부모 노드를 찾아 판별한다.

// 그리고 실제 재귀함수로 Union 연산을 수행하면
// [1 2 3 4 5]
//  1 1 1 4 5
// 형태가 된다.

#include <iostream>
#include <vector>
using namespace std;
vector<int> parent(6);

int getParent(int n) {
  if (parent[n] == n) return n;
  return parent[n] = getParent(parent[n]);

  // 여기서 parent[n] = getParent(parent[n]);인 이유는
  // 찾으면서 경로 압축을 수행하기 위해서이다.
  // 만약 같으 노드에 대해 여러번 호출하면 비효율적이다.
  // 그래서 이후 호출할때 바로 찾을 수 있게 경로를 압축한다.
}

void unionParent(int a, int b) {
  a = getParent(a);
  b = getParent(b);
  if (a < b)
    parent[b] = a;
  else
    parent[a] = b;
  // 연결할때 번호중에 가장 작은 번호를 부모 노드로 설정한다.
}

bool checkParent(int a, int b) {
  a = getParent(a);
  b = getParent(b);
  if (a == b) return true;
  return false;
}

int main() {
  for (int i = 1; i <= 5; ++i) parent[i] = i;
  // [1 2 3 4 5]
  //  1 2 3 4 5

  unionParent(1, 2);
  // [1 2 3 4 5]
  //  1 1 3 4 5

  cout << "1과 2의 연결 여부 : " << checkParent(1, 2) << endl;

  cout << "2와 3의 연결 여부 : " << checkParent(2, 3) << endl;

  unionParent(2, 3);
  // [1 2 3 4 5]
  //  1 1 1 4 5

  cout << "2와 3의 연결 여부 : " << checkParent(2, 3) << endl;
  return 0;
}