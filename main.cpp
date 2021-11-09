#include <iostream>
#include <list>

#include "shortest_path.h"
using namespace std;

int main(int argc, char** argv) {
  ShortestPath spath(30, 0.6);
  list<int> l;
  l.push_back(1);
  l.push_back(3);
  l.push_back(5);
  l.pop_front();
  l.insert(l.begin(), 10);
  for (auto i = l.begin(); i != l.end(); i++) {
    cout << *i << " " << endl;
  }
  return 0;
}