
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

class Graph {
 private:
  bool **graph;
  float density;
  int size;
  int edge_count;

 public:
  Graph(int size = 50, float density = 0.3);
  ~Graph();

  int V() { return size; }
  int E() { return edge_count; }
  bool Adjacent(int x, int y);
  vector<int> Neighbors(int x);
  void Add(int x, int y);
  void Delete(int x, int y);
};
Graph::Graph(int size, float density) : size(size), density(density) {
  srand(time(NULL));
  edge_count = 0;
  graph = new bool *[size];
  for (int i = 0; i < size; i++) {
    graph[i] = new bool[size];
  }
  for (int i = 0; i < size; i++) {
    for (int j = i; j < size; j++) {
      if (i == j) {
        graph[i][j] = false;
      } else {
        graph[i][j] = graph[j][i] =
            static_cast<double>(rand()) / RAND_MAX < density;
        if (graph[i][j]) edge_count++;
      }
    }
  }
}
Graph ::~Graph() {
  for (int i; i < size; i++) {
    delete (graph[i]);
  }
  delete (graph);
}
bool Graph::Adjacent(int x, int y) {
  if (x < 0 || x >= size || y < 0 || y >= size) {
    cout << "Indices out of range!" << endl;
    return false;
  }
  return graph[x][y];
}
vector<int> Graph::Neighbors(int x) {
  vector<int> neighbors;
  for (int i = 0; i < size; i++) {
    if (graph[x][i]) neighbors.push_back(i);
    return neighbors;
  }
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