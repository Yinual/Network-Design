#include <iostream>
#include <vector>
using namespace std;
struct Edge
{
    int src,dest;
    int weight;
};

struct Graph {
    int v;
    vector<Edge> edges; // list of edges
};

void findMST (Graph& g){
    cout <<"\nfindMST function called, but not yet implemented."<< endl;
}

int main(){
    cout<< "kruskal's Algorithm for mst defining structures"<<endl;
    Graph graph;
    graph.v=4;

    graph.edges.push_back({0,1,10});
    graph.edges.push_back({0,2,6});
    graph.edges.push_back({0,3,5});

    cout<< "Graph created with " << graph.v<<" vertices and " <<graph.edges.size()<<" edges."<<endl;
    findMST(graph);
    return 0;
}
