import sys

V = 5  # Number of vertices in the graph

def min_key(key, mst_set):
    min_val = sys.maxsize
    min_index = 0
    for v in range(V):
        if key[v] < min_val and not mst_set[v]:
            min_val = key[v]
            min_index = v
    return min_index

def print_mst(parent, graph):
    print("Edge \tWeight")
    for i in range(1, V):
        print(parent[i], "-", i, "\t", graph[i][parent[i]])

def prim_mst(graph):
    parent = [-1] * V
    key = [sys.maxsize] * V
    mst_set = [False] * V

    key[0] = 0
    parent[0] = -1

    for _ in range(V - 1):
        u = min_key(key, mst_set)
        mst_set[u] = True

        for v in range(V):
            if graph[u][v] and not mst_set[v] and graph[u][v] < key[v]:
                parent[v] = u
                key[v] = graph[u][v]

    print_mst(parent, graph)

if __name__ == "__main__":
    graph = [
        [0, 2, 0, 6, 0],
        [2, 0, 3, 8, 5],
        [0, 3, 0, 0, 7],
        [6, 8, 0, 0, 9],
        [0, 5, 7, 9, 0]
    ]

    prim_mst(graph)
