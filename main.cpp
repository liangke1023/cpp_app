#include <iostream>
#include <list>

#include "shortest_path.h"
using namespace std;

int main(int argc, char** argv) {
  ShortestPath shortest_path(9, 0.33);
  shortest_path.vertices();
  list<int> paths = shortest_path.path(2, 4);
  cout << paths.front();
  paths.pop_front();
  while (paths.size()) {
    cout << " - " << paths.front();
    paths.pop_front();
  }
  cout << endl;
  cout << " path size = " << shortest_path.path_size(2, 4) << endl;

  return 0;
}