#include <iostream>
#include <list>

#include "shortest_path.h"
using namespace std;

int main(int argc, char** argv) {
  float densities[2] = {0.2f, 0.4f};
  const int size = 50;
  for (auto d : densities) {
    ShortestPath shortest_path(size, d, 1, 10);
    shortest_path.vertices();
    int sum_shortest = 0;
    int paths_exist = 0;
    for (int i = 1; i < size; i++) {
      int path_size = shortest_path.path_size(0, i);
      if (path_size > 0) {
        sum_shortest += path_size;
        paths_exist++;
      }
    }
    cout << "average of shortest paths: "
         << static_cast<double>(sum_shortest) / paths_exist << endl;
  }

  return 0;
}