#include <fstream>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
  ifstream file("SampleTestData");
  istream_iterator<int> begin(file), end;
  vector<int> graph(begin, end);
  cout << graph.size() << endl;
  for (int i : graph) cout << i << " ";
  return 0;
}