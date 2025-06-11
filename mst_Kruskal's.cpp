#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

struct Edge { int src, dest, weight; 
    bool operator<(const Edge& o) const { return weight < o.weight; } };
struct DSU { vector<int> parent, rank; DSU(int n) { parent.resize(n); 
    iota(parent.begin(), parent.end(), 0); rank.assign(n, 0); 
} 
int find(int i) { if (parent[i]==i) return i; 
    return parent[i]=find(parent[i]); 
} void unite(int i, int j) { int r_i=find(i), r_j=find(j); 
    if(r_i!=r_j) { if (rank[r_i]<rank[r_j]) parent[r_i]=r_j; 
        else if (rank[r_j]<rank[r_i]) parent[r_j]=r_i; 
    else { parent[r_j]=r_i; rank[r_i]++; 
    }
}
}
};

class Graph {
public:
    int V; vector<Edge> edges;
    Graph(int vertices) : V(vertices) {}
    void addEdge(int src, int dest, int weight) { edges.push_back({src, dest, weight}); }
    
    vector<Edge> kruskalMST() {
        vector<Edge> mst_edges;
        long long total_mst_weight = 0;
        int edges_in_mst = 0; 

        sort(edges.begin(), edges.end());
        DSU dsu(V);
        cout << "\n--- Kruskal's Algorithm Execution ---\n";
        for (const auto& edge : edges) {
            if (dsu.find(edge.src) != dsu.find(edge.dest)) {
                mst_edges.push_back(edge);
                dsu.unite(edge.src, edge.dest);
                total_mst_weight += edge.weight;
                edges_in_mst++;
                cout << "Added edge: " << edge.src << " -- " << edge.dest << " (W: " << edge.weight << ")\n";
                
                if (edges_in_mst == V - 1) break;
            } else {
                cout << "Skipped edge (cycle): " << edge.src << " -- " << edge.dest << " (W: " << edge.weight << ")\n";
            }
        }
        cout << "-------------------------------------\n";
        
        cout << "\nMinimum Spanning Tree (MST) for the Network:\n";
        for (const auto& edge : mst_edges) {
            cout << "Link: Node " << edge.src << " <-> Node " << edge.dest << " | Cost: " << edge.weight << endl;
        }
        cout << "Total Cost of Minimum Spanning Tree: " << total_mst_weight << endl;

        return mst_edges;
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

    vector<Edge> efficient_network_links = communication_network.kruskalMST();
    cout << "\n=========================================================\n";
    return 0;
}