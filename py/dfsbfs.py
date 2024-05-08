from collections import deque

class Graph:
    def __init__(self, V):
        self.V = V
        self.adj = [[] for _ in range(V)]

    def add_edge(self, v, w):
        self.adj[v].append(w)
        self.adj[w].append(v)

    def dfs_util(self, v, visited):
        visited[v] = True
        print(v, end=" ")

        for u in self.adj[v]:
            if not visited[u]:
                self.dfs_util(u, visited)

    def dfs(self, v):
        visited = [False] * self.V
        self.dfs_util(v, visited)
        print()

    def bfs(self, v):
        visited = [False] * self.V
        queue = deque()

        visited[v] = True
        queue.append(v)

        while queue:
            v = queue.popleft()
            print(v, end=" ")

            for u in self.adj[v]:
                if not visited[u]:
                    visited[u] = True
                    queue.append(u)

        print()

if __name__ == "__main__":
    g = Graph(8)
    g.add_edge(0, 1)
    g.add_edge(0, 2)
    g.add_edge(1, 3)
    g.add_edge(1, 4)
    g.add_edge(4, 7)
    g.add_edge(2, 5)
    g.add_edge(2, 6)

    print("DFS starting from vertex 0:", end=" ")
    g.dfs(0)

    print("BFS starting from vertex 0:", end=" ")
    g.bfs(0)
