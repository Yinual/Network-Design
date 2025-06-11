#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge {
    int src, dest;
    int weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};
// Represents a graph using a list of vertices and edges.
struct Graph {
    int V;
    vector<Edge> edges;
};

struct DSU {
    vector<int> parent;
    
    DSU(int n) {
        parent.resize(n);
        for(int i = 0; i < n; ++i) {
            parent[i] = i; 
        }
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        return find(parent[i]);
    }
    
};


void kruskalMST(Graph& g) {
    sort(g.edges.begin(), g.edges.end());

    DSU dsu(g.V);
    cout << "\nDSU structure initialized for " << g.V << " vertices.\n";

}

int main() {
    cout << "===== Kruskal's Algorithm - Adding DSU =====\n";
    Graph graph;
    graph.V = 4;
    graph.edges.push_back({0, 1, 10});
    graph.edges.push_back({1, 2, 2});
    graph.edges.push_back({0, 2, 6});
    kruskalMST(graph);
    return 0;
}
