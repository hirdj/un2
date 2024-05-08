from heapq import heappush, heappop
from typing import List, Tuple

def dijkstra(graph: List[List[Tuple[int, int]]], start: int) -> List[int]:
    V = len(graph)
    dist = [float("inf")] * V
    dist[start] = 0

    pq = [(0, start)]

    while pq:
        u_dist, u = heappop(pq)

        if u_dist > dist[u]:
            continue

        for weight, v in graph[u]:
            if dist[u] + weight < dist[v]:
                dist[v] = dist[u] + weight
                heappush(pq, (dist[v], v))

    return dist

if __name__ == "__main__":
    V = 6
    graph = [
        [(5, 1), (3, 2)],
        [(6, 3), (4, 4)],
        [(1, 3), (9, 5)],
        [(2, 4)],
        [(7, 5)],
        []
    ]

    start = 0
    shortest_distances = dijkstra(graph, start)

    print("Vertex\tDistance from Source")
    for i in range(V):
        print(f"{i}\t{shortest_distances[i]}")
