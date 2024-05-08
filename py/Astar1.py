# Implement A * Algorithm for any game search Problem
import heapq

def heuristic(a, b):
  
    return 0

def a_star(graph, start, goal):
    frontier = []
    heapq.heappush(frontier, (0, start))
    came_from = {start: None}
    cost_so_far = {start: 0}

    while frontier:
        _, current = heapq.heappop(frontier)

        if current == goal:
            break

        for next, cost in graph[current].items():
            new_cost = cost_so_far[current] + cost
            if next not in cost_so_far or new_cost < cost_so_far[next]:
                cost_so_far[next] = new_cost
                priority = new_cost + heuristic(goal, next)
                heapq.heappush(frontier, (priority, next))
                came_from[next] = current

    return came_from, cost_so_far

def reconstruct_path(came_from, start, goal):
    current = goal
    path = []
    while current != start:
        path.append(current)
        current = came_from[current]
    path.append(start)
    return path[::-1]

graph = {
    'A': {'B': 1, 'C': 3},
    'B': {'A': 1, 'D': 2, 'E': 3},
    'C': {'A': 3, 'F': 1},
    'D': {'B': 2, 'E': 1},
    'E': {'B': 3, 'D': 1, 'F': 2,'G':1},
    'F': {'C': 1, 'E': 2,'G':2},
    'G': {'E': 1, 'F': 2}
}

start = 'A'
goal = 'G'

came_from, cost_so_far = a_star(graph, start, goal)
path = reconstruct_path(came_from, start, goal)

print(f"Path from {start} to {goal}: {path}")
print(f"Cost: {cost_so_far[goal]}")
# output
# Path from A to F: ['A', 'C', 'F']
# Cost: 4