#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define NUM_VERTICES 5 // Number of vertices in the graph

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    vector<Edge> edges;
};

Graph* createGraph(int V, int E) {
    Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edges.resize(E);
    return graph;
}

struct Subset {
    int parent;
    int rank;
};

int find(Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void Union(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

bool compare(Edge& a, Edge& b) {
    return a.weight < b.weight;
}

void kruskalMST(Graph* graph) {
    int V = graph->V;
    vector<Edge> result(V - 1);

    sort(graph->edges.begin(), graph->edges.end(), compare);

    Subset* subsets = new Subset[V];
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    int e = 0, i = 0;
    while (e < V - 1 && i < graph->E) {
        Edge next_edge = graph->edges[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    cout << "Edges in MST:" << endl;
    for (i = 0; i < e; ++i) {
        cout << result[i].src << " - " << result[i].dest << " : " << result[i].weight << endl;
    }

    delete[] subsets;
}

int main() {
    int V = NUM_VERTICES, E = 7;
    Graph* graph = createGraph(V, E);

    // Example graph for demonstration
    graph->edges = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 3, 8},
        {1, 4, 5},
        {2, 3, 1},
        {2, 4, 7},
        {3, 4, 9}
    };

    kruskalMST(graph);

    delete graph;

    return 0;
}
