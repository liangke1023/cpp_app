#ifndef GRAPH
#define GRAPH
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

class Graph {
 private:
  bool **graph;
  int **values_edge;
  float density;
  int size;
  int edge_count;
  vector<pair<int, int> > values_node;  // distance and last vertex

 public:
  Graph(int size = 50, float density = 0.3);
  ~Graph();

  int V() { return size; }
  int E() { return edge_count; }
  bool Adjacent(int x, int y);
  vector<int> Neighbors(int x);
  void Add(int x, int y);
  void Delete(int x, int y);
  pair<int, int> get_node_value(int x);
  void set_node_value(int x, pair<int, int> a);
  int get_edge_value(int x, int y);
  void set_edge_value(int x, int y, int v);
};
Graph::Graph(int size, float density) : size(size), density(density) {
  // create a random graph
  srand(time(NULL));
  edge_count = 0;
  graph = new bool *[size];
  values_edge = new int *[size];
  values_node.resize(size);
  for (int i = 0; i < size; i++) {
    graph[i] = new bool[size];
    values_edge[i] = new int[size];
  }
  for (int i = 0; i < size; i++) {
    for (int j = i; j < size; j++) {
      if (i == j) {
        graph[i][j] = false;
      } else {
        graph[i][j] = graph[j][i] =
            static_cast<double>(rand()) / RAND_MAX < density;
        values_edge[i][j] = values_edge[j][i] = rand() % 10;
        if (graph[i][j]) edge_count++;
      }
    }
  }
}
Graph ::~Graph() {
  for (int i; i < size; i++) {
    delete (graph[i]);
    delete (values_edge[i]);
  }
  if (graph != nullptr) delete (graph);
  if (values_edge != nullptr) delete (values_edge);
}
bool Graph::Adjacent(int x, int y) {
  if (x < 0 || x >= size || y < 0 || y >= size) {
    cout << "Indices out of range!" << endl;
    return false;
  }
  return graph[x][y];
}
/**
 * @brief lists all nodes y such that there is an edge from x to v
 *
 * @param x
 * @return vector<int>
 */
vector<int> Graph::Neighbors(int x) {
  vector<int> neighbors;
  for (int i = 0; i < size; i++) {
    if (graph[x][i]) neighbors.push_back(i);
  }
  return neighbors;
}
void Graph::Add(int x, int y) {
  if (x < 0 || x >= size || y < 0 || y >= size) {
    cout << "Indices out of range!" << endl;
    return;
  }
  graph[x][y] = graph[y][x] = true;
  return;
}
void Graph::Delete(int x, int y) {
  if (x < 0 || x >= size || y < 0 || y >= size) {
    cout << "Indices out of range!" << endl;
    return;
  }
  graph[x][y] = graph[y][x] = false;
  return;
}
pair<int, int> Graph::get_node_value(int x) {
  if (x < size) return values_node[x];
  return make_pair(-1, -1);
}
void Graph::set_node_value(int x, pair<int, int> a) {
  if (x < size) values_node[x] = a;
  return;
}
int Graph::get_edge_value(int x, int y) {
  if (x < size && y < size) return values_edge[x][y];
  return -1;
}
void Graph::set_edge_value(int x, int y, int v) {
  if (x < size && y < size) values_edge[x][y] = values_edge[y][x] = v;
}

#endif /* GRAPH */
