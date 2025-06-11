Project Title: Network Design Using Greedy Algorithms for Minimum Spanning Trees

Group Name: Group 8.
Course: Design and Analysis of Algorithm.

      Group member            ID.NO
      
      1,Mihret Bezu          NSR/2481/14
      2,Ynebeb Mosse         NSR/1004/15
      3,Zerubabel Temeselew  NSR/1040/15
      4,Abrham Dile          NSR/465/14
      5,Ashenafi Berihun     NSR/117/15
      
Submition Date: Jun 11/ 2025.

Abstract:
This project investigates the application of greedy algorithms, specifically Kruskal's algorithm, in designing efficient communication networks. 
A C++ program is developed to find the Minimum Spanning Tree (MST) of a given network graph, representing the most cost-effective way to connect 
all nodes. The report details the data structures employed, such as the Disjoint Set Union (DSU) for cycle detection, and analyzes the time 
complexity and overall efficiency of the chosen algorithm.

Introduction

Efficient network design is a critical problem in various domains, from telecommunications and computer networks to transportation 
and utility distribution. The primary goal is often to connect a set of locations or nodes with minimal cost while ensuring full connectivity. 
A graph-theoretic approach provides a powerful framework for modeling such problems, where nodes are represented as vertices and potential 
connections as edges with associated costs or weights.

The Minimum Spanning Tree (MST) of a connected, undirected, and weighted graph is a subgraph that connects all vertices with the minimum 
possible total edge weight, without forming any cycles. Finding an MST is a classic optimization problem that directly addresses the need 
for cost-effective network infrastructure.

Greedy algorithms are a paradigm that makes locally optimal choices at each step with the hope of finding a global optimum. For the MST problem, 
algorithms like Kruskal's and Prim's are well-known greedy approaches that provably find the optimal solution. This project focuses on implementing 
Kruskal's algorithm in C++ to demonstrate its application in designing communication networks and to analyze the data structures and algorithmic 
efficiency involved.

Kruskal's Algorithm: A Greedy Approach

Kruskal's algorithm builds a Minimum Spanning Tree by iteratively adding edges to a growing forest. 
The greedy choice made at each step is to select the edge with the smallest weight from the set of edges not yet considered, 
provided that adding this edge does not form a cycle with the edges already selected.

The algorithm proceeds as follows:
1.  Initialization:
    Create a forest F (a set of trees), where each vertex in the graph is initially a separate tree.
    Create a set S containing all edges in the graph.
    The MST will be stored in a list A (initially empty).
2.  Sort Edges: Sort all edges in S in non-decreasing order of their weights.
3.  Iterative Selection:
    For each edge (u, v) in the sorted list S:
        If vertices u and v are in different trees in the forest F (i.e., adding edge (u, v) does not form a cycle):
            Add edge (u, v) to the MST list A.
            Merge the trees containing u and v in the forest F.
4.  Termination: The algorithm terminates when the MST A contains V-1 edges (where V is the number of vertices) or when 
all edges in S have been considered. If the graph is connected, V-1 edges will be selected.

The Disjoint Set Union (DSU) data structure is typically used to efficiently manage the forest F and check for cycles 
(i.e., determine if two vertices belong to the same tree/component).

Application in Communication Network Design

The implemented Kruskal's algorithm directly models the design of an efficient communication network:
Vertices (Nodes): Represent physical locations such as cities, data centers, routers, or servers that need to be interconnected. 
In the C++ code, these are integers from 0 to V-1.
Edges (Links): Represent potential communication links between pairs of nodes, such as fiber optic cables, microwave links, or wireless connections. 
Each edge has an associated weight.
Weights (Costs): Represent the cost of establishing a link. This cost can be monetary (e.g., cost of laying cable), physical distance, 
latency of the connection, or even inverse bandwidth (higher weight for lower bandwidth if minimizing cost implies maximizing throughput).
Minimum Spanning Tree (MST): The output of Kruskal's algorithm, mst_edges, represents the subset of potential links that should be established 
to connect all nodes with the minimum possible total cost. This ensures that every node can communicate with every other node 
(directly or indirectly through the MST paths) while minimizing the infrastructure investment.

For instance, if a telecommunication company wants to connect several towns, the MST would identify the cheapest set of cable routes 
to ensure all towns are part of the network. 

Data Structures Used

The efficiency and correctness of Kruskal's algorithm heavily rely on the appropriate choice and implementation of data structures:

struct Edge:
    Purpose: To encapsulate the properties of a connection: its source (src), destination (dest), and weight.
    Fields: int src, int dest, int weight.
    Key Feature: Overloading the operator< allows std::vector<Edge> to be easily sorted by std::sort, which is the first crucial step 
    in Kruskal's algorithm.

vector<Edge> edges (within Graph class):
    Purpose: To store all potential edges of the input graph. This list is then sorted.
    Why vector?: Provides dynamic resizing and efficient storage for a collection of edges. Its iterators are compatible with sort.

vector<Edge> mst_edges (within kruskalMST method):
    Purpose: To store the edges that are selected to be part of the Minimum Spanning Tree.
    Why vector?: Suitable for accumulating the resulting edges.
struct DSU (Disjoint Set Union / Union-Find):
    Purpose: This is the most critical data structure for Kruskal's algorithm's efficiency in cycle detection. It maintains a collection 
    of disjoint sets, where each set represents a connected component (a tree) in the currently formed forest.
    Internal Data:
        vector<int> parent;: An array where parent[i] stores the parent of element i. If parent[i] == i, then i is the representative 
        (root) of its set. Initialized by std::iota so each element is its own parent.
        vector<int> rank;: An array used for the Union by Rank optimization. rank[i] stores an upper bound on the height of the tree 
        rooted at i. This helps in keeping the trees relatively flat during union operations.
    Key Operations:
        DSU(int n) (Constructor): Initializes n disjoint sets.
        int find(int i): Returns the representative of the set containing i. It implements Path Compression: during the traversal to find the root, 
        it makes all nodes on the path point directly to the root. This significantly speeds up future find operations.
        void unite(int i, int j): Merges the two sets containing i and j. It uses Union by Rank: when merging two trees, 
        the root of the tree with smaller rank is made a child of the root of the tree with larger rank. If ranks are equal, one is chosen 
        arbitrarily as the parent, and its rank is incremented. This, along with path compression, makes DSU operations nearly constant 
        time on average (amortized).
    Role in Kruskal's: Before adding an edge (u,v) to the MST, the algorithm calls dsu.find(u) and dsu.find(v). If they return the same 
    representative, u and v are already in the same connected component, and adding edge (u,v) would form a cycle. Otherwise, the edge is added, 
    and dsu.unite(u,v) is called to merge their components.

Efficiency of the Algorithms

Let V be the number of vertices (nodes) and E be the number of edges (potential links) in the graph.

Kruskal's Algorithm:
1.  Sorting Edges: The most time-consuming step is typically sorting all E edges by weight. Using an efficient comparison sort like std::sort 
(which is often an Introsort, a hybrid of Quicksort, Heapsort, and Insertion Sort) takes O(E log E) time.
2.  DSU Operations:
    Initialization of DSU: O(V) to initialize parent and rank arrays.
    Iterating through E sorted edges: In the worst case, we might iterate through all E edges. For each edge, we perform two find operations 
    and at most one unite operation.
    With both Path Compression and Union by Rank (or Union by Size) optimizations, a sequence of m DSU operations (find or unite) on n elements 
    takes O(m * α(n)) time, where α(n) is the inverse Ackermann function. The inverse Ackermann function grows extremely slowly; for all 
    practical values of n, α(n) is less than 5. Thus, the DSU operations can be considered nearly constant time on an amortized basis. 
    So, for E edges, this part takes roughly O(E * α(V)).
3.  Overall Complexity for Kruskal's: The dominant factor is the edge sorting. Therefore, the total time complexity of Kruskal's algorithm 
is O(E log E).
    If E is very large (a dense graph, E ≈ V^2), then log E is log(V^2) = 2 log V, so it becomes O(E log V).

Prim's Algorithm (for comparison):
Prim's algorithm is another greedy MST algorithm. Its efficiency depends on the data structure used for the priority queue to select the 
minimum weight edge connecting a vertex in the MST to one outside it.
Using Adjacency List and Binary Heap (like std::priority_queue): O((V+E) log V) or simply O(E log V) if E >= V-1 (for connected graphs).
Using Adjacency List and Fibonacci Heap: O(E + V log V). This is asymptotically faster for dense graphs where E is close to V^2.
Using Adjacency Matrix (naive Prim's): O(V^2).

Comparison for Greedy MST Algorithms:
Kruskal's (O(E log E)) is generally simpler to implement and often preferred for sparse graphs (where E is much smaller than V^2, e.g., E is O(V)).
Prim's (e.g., O(E log V) with a binary heap) can be more efficient for dense graphs because log V is typically smaller than log E 
(since E can be up to O(V^2)).

Program Output and Interpretation (Example based on the provided code)

(The C++ program output, showing edges processed, MST links, and total cost, would be included here in the full project report. 
Example output was shown previously but is part of the "program execution" rather than static documentation.)

Example interpretation:
The "Edges sorted..." section (from program output) shows the greedy choices being made.
"Added edge:" lines indicate links chosen for the efficient network because they are the cheapest available option that doesn't create a 
redundant connection (cycle).
"Skipped edge (forms cycle):" lines show links that were considered but rejected because they would connect two parts of the network that 
are already connected, thus being unnecessary and adding to the cost.
The "Minimum Spanning Tree (MST) for the Network:" lists the final set of links forming the most cost-effective backbone connecting all nodes.
"Total Cost of Minimum Spanning Tree: [Value]" is the minimum possible cost to achieve full connectivity in the example network.

Conclusion

This project successfully demonstrated the application of greedy algorithms, specifically Kruskal's algorithm, for designing efficient 
communication networks. By representing the network as a graph and finding its Minimum Spanning Tree, we can determine the most cost-effective 
way to connect all nodes.

The C++ implementation highlighted the crucial role of data structures: the Edge structure for representing links, vector for managing 
collections of edges, and most importantly, the Disjoint Set Union (DSU) structure with path compression and union by rank optimizations for 
efficient cycle detection.

Kruskal's algorithm, with a time complexity of O(E log E), provides an efficient and provably optimal solution for the MST problem. This makes 
it a valuable tool in practical network design scenarios where minimizing infrastructure cost while maintaining full connectivity is paramount. 
The greedy strategy of always picking the cheapest safe edge proves effective in achieving this global optimum.
