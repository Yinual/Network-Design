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
