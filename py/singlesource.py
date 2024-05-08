import heapq
from typing import List, Tuple

Graph = List[List[Tuple[int, int]]]

def dijkstra(graph: Graph, start: int) -> List[int]:
    V = len(graph)
    dist = [float("inf")] * V
    dist[start] = 0

    pq = [(0, start)]

    while pq:
        u_dist, u = heapq.heappop(pq)

        if u_dist > dist[u]:
            continue

        for v, weight in graph[u]:
            if dist[u] + weight < dist[v]:
                dist[v] = dist[u] + weight
                heapq.heappush(pq, (dist[v], v))

    return dist

if __name__ == "__main__":
    V = 6
    graph: Graph = [[] for _ in range(V)]

    # Example graph for demonstration
    graph[0].append((1, 5))
    graph[0].append((2, 3))
    graph[1].append((3, 6))
    graph[1].append((4, 4))
    graph[2].append((3, 1))
    graph[2].append((5, 9))
    graph[3].append((4, 2))
    graph[4].append((5, 7))

    start = 0
    shortest_distances = dijkstra(graph, start)

    print("Vertex\tDistance from Source")
    for i in range(V):
        print(i, "\t", shortest_distances[i])
