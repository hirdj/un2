class Subset:
    def __init__(self, parent, rank):
        self.parent = parent
        self.rank = rank

def find(subsets, i):
    if subsets[i].parent != i:
        subsets[i].parent = find(subsets, subsets[i].parent)
    return subsets[i].parent

def union(subsets, x, y):
    xroot = find(subsets, x)
    yroot = find(subsets, y)

    if subsets[xroot].rank < subsets[yroot].rank:
        subsets[xroot].parent = yroot
    elif subsets[xroot].rank > subsets[yroot].rank:
        subsets[yroot].parent = xroot
    else:
        subsets[yroot].parent = xroot
        subsets[xroot].rank += 1

def kruskal_mst(graph):
    V = len(graph["edges"])
    result = []

    graph["edges"].sort(key=lambda x: x["weight"])

    subsets = [Subset(i, 0) for i in range(V)]

    e = 0
    i = 0
    while e < V - 1 and i < len(graph["edges"]):
        next_edge = graph["edges"][i]
        i += 1

        x = find(subsets, next_edge["src"])
        y = find(subsets, next_edge["dest"])

        if x != y:
            result.append(next_edge)
            e += 1
            union(subsets, x, y)

    print("Edges in MST:")
    for edge in result:
        print(edge["src"], "-", edge["dest"], ":", edge["weight"])

if __name__ == "__main__":
    graph = {
        "edges": [
            {"src": 0, "dest": 1, "weight": 2},
            {"src": 0, "dest": 3, "weight": 6},
            {"src": 1, "dest": 3, "weight": 8},
            {"src": 1, "dest": 4, "weight": 5},
            {"src": 2, "dest": 3, "weight": 1},
            {"src": 2, "dest": 4, "weight": 7},
            {"src": 3, "dest": 4, "weight": 9}
        ]
    }

    kruskal_mst(graph)
