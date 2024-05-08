import sys

def min_key(key, mst_set):
    min_val = sys.maxsize
    min_index = -1
    for v in range(len(key)):
        if not mst_set[v] and key[v] < min_val:
            min_val = key[v]
            min_index = v
    return min_index

def print_mst(parent, graph):
    print("Edge \tWeight")
    for i in range(1, len(graph)):
        print(parent[i], "-", i, "\t", graph[i][parent[i]])

def prim_mst(graph):
    V = len(graph)
    parent = [-1] * V
    key = [sys.maxsize] * V
    mst_set = [False] * V

    key[0] = 0
    parent[0] = -1

    for _ in range(V):
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
