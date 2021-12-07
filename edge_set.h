#ifndef EDGE_SET
#define EDGE_SET
#include <algorithm>
#include <vector>
struct Edge {
  int vertex0;  // vertex closed
  int vertex1;  // vertex open
  int length;
};
bool MiniEdge(Edge &a, Edge &b) { return a.length > b.length; }

class EdgeSet {
  vector<Edge> edges;

 public:
  EdgeSet(){};
  ~EdgeSet(){};
  void Insert(Edge &edge);
  Edge Pop();
  int Size() { return edges.size(); }
};

void EdgeSet::Insert(Edge &edge) {
  for (auto &i : edges) {
    if ((i.vertex0 == edge.vertex0 && i.vertex1 == edge.vertex1) ||
        (i.vertex0 == edge.vertex1 && i.vertex1 == edge.vertex0))
      return;
  }
  edges.push_back(edge);
  sort(edges.begin(), edges.end(), MiniEdge);
}
Edge EdgeSet::Pop() {
  Edge res;
  if (edges.size() > 0) {
    res = edges.back();
    edges.pop_back();
  }
  return res;
}

#endif /* EDGE_SET */
