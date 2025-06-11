#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

struct Edge { int src, dest, weight; bool operator<(const Edge& other) const { return weight < other.weight; } };
struct DSU {
    vector<int> parent;
    vector<int> rank;

    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0); 
        rank.assign(n, 0);
    }
    
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            if (rank[root_i] < rank[root_j]) parent[root_i] = root_j;
            else if (rank[root_j] < rank[root_i]) parent[root_j] = root_i;
            else { parent[root_j] = root_i; rank[root_i]++; }
        }
    }
};

class Graph {
public:
    int V;
    vector<Edge> edges;
    Graph(int vertices) : V(vertices) {}
    void addEdge(int src, int dest, int weight) { edges.push_back({src, dest, weight}); }
    void kruskalMST() {
        vector<Edge> mst_edges; long long total_mst_weight = 0;
        sort(edges.begin(), edges.end());
        DSU dsu(V);
        cout << "\n--- Kruskal's Algorithm Execution ---\n";
        for (const auto& edge : edges) {
            int r_s = dsu.find(edge.src), r_d = dsu.find(edge.dest);
            if (r_s != r_d) {
                mst_edges.push_back(edge); dsu.unite(edge.src, edge.dest);
                total_mst_weight += edge.weight;
                cout << "Added edge: " << edge.src << " -- " << edge.dest << " (Weight: " << edge.weight << ")\n";
            } else {
                cout << "Skipped edge (forms cycle): " << edge.src << " -- " << edge.dest << " (Weight: " << edge.weight << ")\n";
            }
        }
        cout << "-------------------------------------\n";
        cout << "Total Cost of Minimum Spanning Tree: " << total_mst_weight << endl;
    }
};

int main() {
    cout << "===== Network Design using Kruskal's Algorithm for MST =====\n";
    Graph communication_network(4);
    communication_network.addEdge(0, 1, 10); 
    communication_network.addEdge(1, 3, 1);
    communication_network.addEdge(2, 3, 4); 
    communication_network.addEdge(0, 2, 6);
    communication_network.addEdge(0, 3, 5);
    communication_network.kruskalMST();
    return 0;
}
