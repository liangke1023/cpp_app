#ifndef JP_MST
#define JP_MST
#include <vector>

#include "edge_set.h"
#include "graph.h"

class JarnikPrimMST {
  vector<int> vertices;
  vector<int> edges;
  // edges for next step available
  EdgeSet edge_set;

 public:
  JarnikPrimMST(Graph &graph, int start);
  ~JarnikPrimMST(){};
  vector<int> ShowVertices() { return vertices; };
  vector<int> ShowEdges() { return edges; };
};
/**
 * @brief calculate the mst with Jarnik Prim for the given graph
 *
 * @param graph
 * @param start start vertex
 */
JarnikPrimMST::JarnikPrimMST(Graph &graph, int start) {
  int current = start;
  vertices.push_back(start);
  while (vertices.size() < graph.V()) {
    vector<int> neighbors = graph.Neighbors(current);
    for (auto &i : neighbors) {
      if (find(vertices.begin(), vertices.end(), i) == vertices.end()) {
        // only insert vertices is are not already in close set
        Edge edge;
        edge.vertex0 = current;
        edge.vertex1 = i;
        edge.length = graph.get_edge_value(current, i);
        // insert and sort
        edge_set.Insert(edge);
      }
    }
    // no other vertices can be found
    if (edge_set.Size() == 0) break;
    Edge new_edge;
    do {
      // check if the shortest edge is already in close set, edges will be
      // selected
      new_edge = edge_set.Pop();
      // vertex 0 is already in close set, continue if both vertices in close
      // set, this edge will be deleted
      current = new_edge.vertex1;
      if (find(vertices.begin(), vertices.end(), current) == vertices.end()) {
        // current is a new vertex
        vertices.push_back(current);
        edges.push_back(new_edge.length);
        break;
      }
    } while (edge_set.Size() > 0);
  }
}

#endif /* JP_MST */
