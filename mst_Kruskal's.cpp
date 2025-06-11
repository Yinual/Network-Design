#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge { int src, dest, weight; 
    bool operator<(const Edge& o) const { return weight < o.weight; 
    } 
};
struct Graph { int V; vector<Edge> edges; 
    Graph(int vertices) : V(vertices) {}
};

struct DSU {
    vector<int> parent;
    DSU(int n) { parent.resize(n); 
        for(int i=0; i<n; ++i) parent[i]=i; }

    int find(int i) {
        if (parent[i] == i) return i;
        return find(parent[i]);
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if(root_i != root_j) {
            parent[root_i] = root_j;
        }
    }
};

void kruskalMST(Graph& g) {
    vector<Edge> mst_edges;
    long long total_mst_weight = 0;
    
    sort(g.edges.begin(), g.edges.end());

    DSU dsu(g.V);

    cout << "\n--- Kruskal's Algorithm Execution ---\n";
    for (const auto& edge : g.edges) {
        int root_src = dsu.find(edge.src);
        int root_dest = dsu.find(edge.dest);

        if (root_src != root_dest) {
            mst_edges.push_back(edge);
            dsu.unite(edge.src, edge.dest);
            total_mst_weight += edge.weight;
            cout << "Added edge: " << edge.src << " -- " << edge.dest << "\n";
        }
    }
    cout << "-------------------------------------\n";
    cout << "Total Cost of Minimum Spanning Tree: " << total_mst_weight << endl;
}

int main() {
    cout << "===== Network Design using Kruskal's Algorithm =====\n";
    Graph network(4);
    network.edges.push_back({0, 1, 10});
    network.edges.push_back({1, 2, 2});
    network.edges.push_back({0, 2, 6});
    network.edges.push_back({2, 3, 4});
    network.edges.push_back({0, 3, 5});
    network.edges.push_back({1, 3, 1}); 

    kruskalMST(network);
    return 0;
}
