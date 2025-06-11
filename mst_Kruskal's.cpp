
#include <iostream>
#include <vector>
#include <algorithm> 
#include <numeric>   // For iota

using namespace std; 

struct Edge {
    int src, dest;
    int weight;

    // operator< for sorting edges by weight
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

struct DSU {
    vector<int> parent;
    vector<int> rank;

    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0); 
        rank.assign(n, 0); // Initialize rank of all elements to 0
    }

    // Find operation with path compression
    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i]); // Path compression
    }

    // Unite operation with union by rank
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);

        if (root_i != root_j) {
            if (rank[root_i] < rank[root_j]) {
                parent[root_i] = root_j;
            } else if (rank[root_j] < rank[root_i]) {
                parent[root_j] = root_i;
            } else {
                parent[root_j] = root_i; 
                rank[root_i]++;         // Increment rank of the new root
            }
        }
    }
};

class Graph {
public:
    int V; // Number of vertices
    vector<Edge> edges; // All edges in the graph

    Graph(int vertices) : V(vertices) {}

    void addEdge(int src, int dest, int weight) {
        edges.push_back({src, dest, weight});
    }

    vector<Edge> kruskalMST() {
        vector<Edge> mst_edges;
        mst_edges.reserve(max(0, V - 1)); 

        long long total_mst_weight = 0;

        sort(edges.begin(), edges.end()); // Sort edges by weight

        DSU dsu(V);
        int edges_in_mst = 0;

        // Optimized: use '\n' instead of endl for potentially faster I/O
        cout << "\n--- Kruskal's Algorithm Execution ---\n";
        cout << "Processing edges sorted by weight:\n";

        for (const auto& edge : edges) {
            int root_src = dsu.find(edge.src);
            int root_dest = dsu.find(edge.dest);

            // If including this edge does not form a cycle
            if (root_src != root_dest) {
                mst_edges.push_back(edge);
                dsu.unite(edge.src, edge.dest);
                total_mst_weight += edge.weight;
                edges_in_mst++;

                cout << "Added edge: " << edge.src << " -- " << edge.dest
                          << " (Weight: " << edge.weight << ")\n";
                
                // MST is complete if it has V-1 edges (for V >= 1).
                // This condition also correctly handles V=0 (V-1 is -1, never met)
                // and V=1 (V-1 is 0, met when edges_in_mst is 0, breaking immediately).
                if (edges_in_mst == V - 1) { 
                    break;
                }
            } else {
                cout << "Skipped edge (forms cycle): " << edge.src << " -- "
                          << edge.dest << " (Weight: " << edge.weight << ")\n";
            }
        }
        cout << "-------------------------------------\n";
        
        // Check if MST could be formed
        // (V > 0 && edges_in_mst < V - 1) means graph is disconnected or not all V-1 edges were found.
        if (V > 0 && edges_in_mst < V - 1) { 
            cout << "\nMST could not be formed completely (Graph might be disconnected).\n";
            cout << "Number of edges in MST found: " << edges_in_mst << "\n";
        } else if (V == 0) {
             cout << "\nMST for an empty graph.\n";
        } else { // MST successfully formed or V=1 (0 edges MST)
            cout << "\nMinimum Spanning Tree (MST) for the Network:\n";
            for (const auto& edge : mst_edges) {
                cout << "Link: Node " << edge.src << " <-> Node " << edge.dest
                          << " | Cost: " << edge.weight << '\n'; 
            }
        }
        cout << "Total Cost of Minimum Spanning Tree: " << total_mst_weight << '\n'; // Changed endl to \n

        return mst_edges;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL); 

    // Optimized: use '\n' instead of endl
    cout << "===== Network Design using Kruskal's Algorithm for MST =====\n";

    int num_nodes = 6;
    Graph communication_network(num_nodes);

    communication_network.addEdge(0, 1, 4);
    communication_network.addEdge(0, 2, 3);
    communication_network.addEdge(1, 2, 1);
    communication_network.addEdge(1, 3, 2);
    communication_network.addEdge(2, 3, 4);
    communication_network.addEdge(2, 4, 3);
    communication_network.addEdge(3, 4, 2);
    communication_network.addEdge(4, 5, 6);
    communication_network.addEdge(0, 3, 10); 

    communication_network.kruskalMST();

    cout << "\n=========================================================\n";
    return 0;
}
