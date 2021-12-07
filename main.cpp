#include <fstream>
#include <iostream>
#include <vector>

#include "graph.h"
#include "jp_mst.h"

using namespace std;

int main(int argc, char** argv) {
  ifstream file("SampleTestData");
  istream_iterator<int> begin(file), end;
  vector<int> input(begin, end);
  Graph graph(input);
  graph.ShowGraph();
  JarnikPrimMST mst(graph, 0);
  auto mst_vertex = mst.ShowVertices();
  auto mst_edge = mst.ShowEdges();
  cout << "Vertices of MST: " << endl;
  for (auto i : mst_vertex) cout << i << " ";
  cout << "\nEdges of MST: " << endl;
  for (auto i : mst_edge) cout << i << " ";
  cout << endl;

  return 0;
}