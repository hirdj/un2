#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii; // (vertex, weight)
typedef vector<vector<pii>> Graph;

vector<int> dijkstra(const Graph& graph, int start) {
    int V = graph.size();
    vector<int> dist(V, INT_MAX);
    dist[start] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int u_dist = pq.top().first;
        pq.pop();

        if (u_dist > dist[u]) {
            continue; // Skip if we have already found a better path to u
        }

        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    int V = 6;
    Graph graph(V);

    // Example graph for demonstration
    graph[0].push_back({1, 5});
    graph[0].push_back({2, 3});
    graph[1].push_back({3, 6});
    graph[1].push_back({4, 4});
    graph[2].push_back({3, 1});
    graph[2].push_back({5, 9});
    graph[3].push_back({4, 2});
    graph[4].push_back({5, 7});

    int start = 0;
    vector<int> shortest_distances = dijkstra(graph, start);

    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; ++i) {
        cout << i << "\t" << shortest_distances[i] << endl;
    }

    return 0;
}
