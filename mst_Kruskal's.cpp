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

void kruskalMST(Graph& g) {
    sort(g.edges.begin(), g.edges.end());
    
    cout << "\n--- Kruskal's Algorithm Execution ---\n";
    cout << "Edges sorted by weight:\n";
    for(const auto& edge : g.edges) {
        cout << "Edge " << edge.src << "-" << edge.dest << " Weight: " << edge.weight << endl;
    }

}

int main() {
    cout << "===== Kruskal's Algorithm - Sorting Step =====\n";
    
    Graph graph;
    graph.V = 4;
    graph.edges.push_back({0, 1, 10});
    graph.edges.push_back({1, 2, 2}); 
    graph.edges.push_back({0, 2, 6});
    graph.edges.push_back({2, 3, 4});
    graph.edges.push_back({0, 3, 5});

    kruskalMST(graph);
    
    return 0;
}
