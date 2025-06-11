#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge { int src, dest, weight; 
    bool operator<(const Edge& o) const { return weight < o.weight; 
    } 
};

    struct DSU {
    vector<int> parent;
    DSU(int n) { parent.resize(n); 
        for(int i=0; i<n; ++i) parent[i]=i; 
    }
    int find(int i) { 
        if (parent[i] == i) return i; 
        return find(parent[i]); 
    }
    void unite(int i, int j) { 
        int r_i=find(i), r_j=find(j); 
        if(r_i != r_j) parent[r_i] = r_j; 
    }
};

class Graph {
public:
    int V;
    vector<Edge> edges;

    Graph(int vertices) : V(vertices) {}

    void addEdge(int src, int dest, int weight) {
        edges.push_back({src, dest, weight});
    }

    void kruskalMST() 
    {
        vector<Edge> mst_edges;
        long long total_mst_weight = 0;
        
        sort(edges.begin(), edges.end());
        DSU dsu(V);
        
        cout << "\n--- Kruskal's Algorithm Execution ---\n";
        cout << "Processing edges sorted by weight:\n";

        for (const auto& edge : edges) {
            int root_src = dsu.find(edge.src);
            int root_dest = dsu.find(edge.dest);
            if (root_src != root_dest) {
                mst_edges.push_back(edge);
                dsu.unite(edge.src, edge.dest);
                total_mst_weight += edge.weight;
                cout << "Added edge: " << edge.src << " -- " << edge.dest << " (Weight: " << edge.weight << ")\n";
            } else {
                cout << "Skipped edge (forms cycle): " << edge.src << " -- " << edge.dest << " (Weight: " << edge.weight << ")\n";
            }
        }
        cout << "-------------------------------------\n";
        cout << "Total Cost of Minimum Spanning Tree: " << total_mst_weight << std::endl;
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
