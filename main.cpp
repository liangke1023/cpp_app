#include <iostream>

using namespace std;

class Graph {
 private:
  bool **graph;
  float density;
  int size;

 public:
  Graph(int size = 50, float density = 0.3);
};
Graph::Graph(int size, float density) : size(size), density(density) {
  cout << "size " << size << " density " << density << endl;
}

int main(int argc, char **argv) {
  Graph g;
  return 0;
}