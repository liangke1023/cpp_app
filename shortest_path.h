#ifndef SHORTEST_PATH
#define SHORTEST_PATH
#include <list>
#include <queue>
#include <vector>

#include "graph.h"
#include "mypriority_queue.h"

using namespace std;

class ShortestPath {
 private:
  Graph g;
  MyPriorityQueue pqueue;

 public:
  ShortestPath(int v, float density) : g(v, density) {
    pqueue.chgPriority(true);
  };
  ShortestPath(){};
  ~ShortestPath(){};
  void vertices();
  list<int> path(int, int);
  int path_size(int, int);
};

void ShortestPath::vertices() {
  // show vertices and edges
  int num_vertices = g.V();
  for (int v = 0; v < num_vertices; v++) {
    for (int i = v + 1; i < num_vertices; i++) {
      if (g.Adjacent(v, i))
        cout << "Edge between vertex " << v << " and " << i << " has length "
             << g.get_edge_value(v, i) << endl;
    }
  }
  return;
}

list<int> ShortestPath::path(int s, int t) {
  list<int> paths;
  int current = s;
  // reset all node values
  for (int i = 0; i < g.V(); i++) {
    g.set_node_value(i, make_pair(-1, -1));
  }

  // first vertice is zero
  g.set_node_value(s, make_pair(0, -1));
  while (current != t) {
    vector<int> neighbors = g.Neighbors(current);
    for (int i = 0; i < neighbors.size(); i++) {
      if (g.get_node_value(neighbors.at(i)).first < 0) {
        int edge = g.get_edge_value(current, neighbors.at(i)) +
                   g.get_node_value(current).first;
        pqueue.insert(make_pair(neighbors.at(i), make_pair(edge, current)));
      }
    }
    if (pqueue.size() == 0) {
      cout << "Can not find path from " << s << " to " << t << endl;
      return paths;
    }
    current = pqueue.top().first;
    g.set_node_value(pqueue.top().first, pqueue.top().second);
    pqueue.minPriority();
  }
  if (current == t) {
    while (current != s) {
      paths.push_front(current);
      current = g.get_node_value(current).second;
    }
    paths.push_front(s);
    return paths;
  }
  return paths;
}

int ShortestPath::path_size(int s, int t) {
  list<int> paths = this->path(s, t);
  return g.get_node_value(paths.back()).first;
}

#endif /* SHORTEST_PATH */
