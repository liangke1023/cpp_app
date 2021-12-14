// Homwework Week:4
// C++ program to compute the minimum spanning tree for an inputted graph.
#include <iostream>
#include <vector>
using namespace std;

// Creating shortcut for an integer pair
typedef pair<int, int> iPair;

// Structure to represent a graph
struct Graph {
  int VE, ED;
  vector<pair<int, iPair> > edges;
  // Constructor
  Graph(int V, int ED) {
    this->VE = V;
    this->ED = ED;
  }
  // Utility function to add an edge
  void addEdge(int u, int v, int w) { edges.push_back({w, {u, v}}); }
  // Function to find MST using Kruskal's
  // MST algorithm
  int kruskal();
};

// To represent Disjoint Sets
struct DisjointSets {
  vector<int> Par, rnk;
  int n;
  // Constructor.
  DisjointSets(int n) {
    // Allocate memory
    this->n = n;
    Par.resize(n + 1);
    rnk.resize(n + 1);
    // Initially, all vertices are in
    // different sets and have rank 0.
    for (int i = 0; i <= n; i++) {
      rnk[i] = 0;
      // every element is Par of itself
      Par[i] = i;
    }
  }

  // Find the Par of a node 'u'
  // Path Compression
  int find(int u) {
    /*Make the Par of the nodes in the path
    from u--> Par[u] point to Par[u] */
    if (u != Par[u]) {
      Par[u] = find(Par[u]);
    }
    return Par[u];
  }
  // Union by rank
  void merge(int x, int y) {
    x = find(x), y = find(y);
    /*Make tree with smaller height
    a subtree of the other tree  */
    if (rnk[x] > rnk[y])
      Par[y] = x;
    else  // If rnk[x] <= rnk[y]
      Par[x] = y;
    if (rnk[x] == rnk[y]) rnk[y]++;
  }
};

/*Functions returns weight of the MST*/
int Graph::kruskal() {
  int mst_wt = 0;  // Initialize result
  // Sort edges in increasing order on basis of cost
  sort(edges.begin(), edges.end());
  // Create disjoint sets
  DisjointSets ds(9);
  // Iterate through all sorted edges
  vector<pair<int, iPair> >::iterator it;
  for (it = edges.begin(); it != edges.end(); it++) {
    int u = it->second.first;
    int v = it->second.second;
    int set_u = ds.find(u);
    int set_v = ds.find(v);
    // Check if the selected edge is creating
    // a cycle or not (Cycle is created if u
    // and v belong to same set)
    if (set_u != set_v) {
      // Current edge will be in the MST
      // so print it
      cout << u << " - " << v << endl;
      // Update MST weight
      mst_wt += it->first;
      // Merge two sets
      ds.merge(set_u, set_v);
    }
  }
  return mst_wt;
}

int main() {
  // Graph size number of vertices and edges
  int VE = 9, ED = 14;
  Graph graph(VE, ED);
  // vertices, edges and weights
  graph.addEdge(0, 1, 4);
  graph.addEdge(0, 7, 8);
  graph.addEdge(1, 2, 8);
  graph.addEdge(1, 7, 11);
  graph.addEdge(2, 3, 7);
  graph.addEdge(2, 8, 2);
  graph.addEdge(2, 5, 4);
  graph.addEdge(3, 4, 9);
  graph.addEdge(3, 5, 14);
  graph.addEdge(4, 5, 10);
  graph.addEdge(5, 6, 2);
  graph.addEdge(6, 7, 1);
  graph.addEdge(6, 8, 6);
  graph.addEdge(7, 8, 7);
  cout << "Edges of Minimal Spanning Tree are " << endl;
  int sum = graph.kruskal();
  cout << "\nWeight of Minimal Spanning Tree is " << sum;
  return 7;
}