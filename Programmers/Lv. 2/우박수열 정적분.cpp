#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
  vector<double> answer;

  vector<pair<double, double>> graph;
  int x = 0;
  while (k != 1) {
    graph.push_back(make_pair(x++, k));
    if (k % 2 == 0)
      k /= 2;
    else
      k = 3 * k + 1;
  }
  graph.push_back(make_pair(x, k));

  vector<double> area(x + 1, 0.0f);

  // for(auto gr :graph)
  // {
  //     cout<<gr.first<<" "<<gr.second<<endl;
  // }

  for (int g = 1; g <= x; ++g) {
    area[g] = (graph[g - 1].second + graph[g].second) / 2;
  }

  // for(auto a : area)cout<<a<<" ";
  // cout<<endl;

  vector<double> addsum(x + 1, 0.0f);
  addsum[1] = area[1];
  for (int i = 2; i <= x; ++i) {
    addsum[i] += area[i] + addsum[i - 1];
  }

  // for(int i=0;i<addsum.size();++i)cout<<addsum[i]<<" ";

  for (auto rg : ranges) {
    int s = rg[0];
    int e = x + rg[1];

    if (e > s) {
      double temp = addsum[e] - addsum[s];
      ostringstream oss;
      oss << std::fixed << std::setprecision(1) << temp;

      answer.push_back(temp);
    } else if (s > e)
      answer.push_back(-1.0f);
    else
      answer.push_back(0.0f);
  }

  return answer;
}