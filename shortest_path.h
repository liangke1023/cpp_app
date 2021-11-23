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
  ShortestPath(int v, float density, int min_edge, int max_edge)
      : g(v, density, min_edge, max_edge) {
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
  for (int i = 0; i < num_vertices; i++) cout << "  " << i;
  cout << endl;
  for (int v = 0; v < num_vertices; v++) {
    cout << v;
    for (int i = 0; i < num_vertices; i++) {
      if (g.Adjacent(v, i))
        cout << "  " << g.get_edge_value(v, i);
      else
        cout << "  " << 0;
    }
    cout << endl;
  }
  return;
}

list<int> ShortestPath::path(int start, int terminal) {
  list<int> paths;
  int current = start;
  // reset all node values
  for (int i = 0; i < g.V(); i++) {
    g.set_node_value(i, make_pair(-1, -1));
  }
  cout << "find " << terminal << endl;
  // first vertice is zero
  g.set_node_value(start, make_pair(0, -1));
  while (current != terminal) {
    cout << "current: " << current << " ";
    vector<int> neighbors = g.Neighbors(current);
    for (auto &vertex : neighbors) {
      if (g.get_node_value(vertex).first < 0) {
        // while the shortest path for this vertex not found yet
        NodeInfo node_info;
        node_info.index = vertex;
        node_info.last_node = current;
        node_info.path_size =
            g.get_edge_value(current, vertex) + g.get_node_value(current).first;
        pqueue.insert(node_info);
      }
    }
    if (pqueue.Size() == 0) {
      // cout << "Can not find path from " << s << " to " << t << endl;
      cout << endl;
      return paths;
    }
    NodeInfo top_node_info = pqueue.top();
    current = top_node_info.index;
    g.set_node_value(top_node_info.index, make_pair(top_node_info.path_size,
                                                    top_node_info.path_size));
    pqueue.minPriority();
  }
  if (current == terminal) {
    while (current != start) {
      paths.push_front(current);
      current = g.get_node_value(current).second;
    }
    paths.push_front(start);
    cout << "\n" << endl;
    return paths;
  }
  return paths;
}

int ShortestPath::path_size(int s, int t) {
  list<int> paths = this->path(s, t);
  if (paths.back() != t) {
    return -1;
  }
  return g.get_node_value(paths.back()).first;
}

#endif /* SHORTEST_PATH */
