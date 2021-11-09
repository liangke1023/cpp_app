#ifndef SHORTEST_PATH
#define SHORTEST_PATH
#include <list>
#include <queue>

#include "graph.h"

using namespace std;

struct myComp {
  constexpr bool operator()(pair<int, int> const &a,
                            pair<int, int> const &b) const noexcept {
    return a.second > b.second;
  }
};
class ShortestPath {
 private:
  Graph g;
  priority_queue<pair<int, int>, vector<pair<int, int> >, myComp> pq;

 public:
  ShortestPath(int v, float density) : g(v, density){};
  ShortestPath(){};
  ~ShortestPath(){};
  list<int> path(int, int);
};

list<int> ShortestPath::path(int s, int t) {
  list<int> paths;
  int current = s;
  // reset all node values
  for (int i = 0; i < g.V(); i++) {
    g.set_node_value(i, -1);
  }
  g.set_node_value(s, 0);
  while (current != t) {
    vector<int> neighbors = g.Neighbors(current);
    for (int i = 0; i < neighbors.size(); i++) {
      if (g.get_node_value(neighbors.at(i)) < 0) {
        int edge = g.get_edge_value(current, neighbors.at(i));
        pq.push(make_pair(neighbors.at(i), edge));
      }
    }
    current = pq.top().first;
    g.set_node_value(pq.top().first, pq.top().second);
    pq.pop();
  }
  return paths;
}

#endif /* SHORTEST_PATH */
