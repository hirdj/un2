#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm> 

using namespace std;

struct Node {
    char id;
    int f_score;
    Node(char id, int f_score) : id(id), f_score(f_score) {}
    bool operator<(const Node& other) const {
        return f_score > other.f_score;
    }
};

int heuristic(char a, char b) {
    return 0; // No heuristic, always return 0
}

std::pair<std::unordered_map<char, char>, std::unordered_map<char, int>> a_star(std::unordered_map<char, std::unordered_map<char, int>>& graph, char start, char goal) {
    std::priority_queue<Node> frontier;
    frontier.emplace(start, 0);
    std::unordered_map<char, char> came_from;
    std::unordered_map<char, int> cost_so_far;
    came_from[start] = '\0';
    cost_so_far[start] = 0;

    while (!frontier.empty()) {
        Node current = frontier.top();
        frontier.pop();

        if (current.id == goal) {
            break;
        }

        for (const auto& neighbor : graph[current.id]) {
            char next = neighbor.first;
            int new_cost = cost_so_far[current.id] + neighbor.second;
            if (cost_so_far.find(next) == cost_so_far.end() || new_cost < cost_so_far[next]) {
                cost_so_far[next] = new_cost;
                int priority = new_cost + heuristic(goal, next);
                frontier.emplace(next, priority);
                came_from[next] = current.id;
            }
        }
    }

    return {came_from, cost_so_far};
}

std::vector<char> reconstruct_path(const std::unordered_map<char, char>& came_from, char start, char goal) {
    std::vector<char> path;
    char current = goal;
    while (current != start) {
        path.push_back(current);
        current = came_from.at(current);
    }
    path.push_back(start);
    std::reverse(path.begin(), path.end());
    return path;
}

int main() {
    std::unordered_map<char, std::unordered_map<char, int>> graph = {
        {'A', {{'B', 1}, {'C', 3}}},
        {'B', {{'A', 1}, {'D', 2}, {'E', 3}}},
        {'C', {{'A', 3}, {'F', 1}}},
        {'D', {{'B', 2}, {'E', 1}}},
        {'E', {{'B', 3}, {'D', 1}, {'F', 2}, {'G', 1}}},
        {'F', {{'C', 1}, {'E', 2}, {'G', 2}}},
        {'G', {{'E', 1}, {'F', 2}}}
    };

    char start = 'A';
    char goal = 'G';

    auto [came_from, cost_so_far] = a_star(graph, start, goal);
    std::vector<char> path = reconstruct_path(came_from, start, goal);

    std::cout << "Path from " << start << " to " << goal << ": ";
    for (char node : path) {
        std::cout << node << " ";
    }
    std::cout << std::endl;

    std::cout << "Cost: " << cost_so_far[goal] << std::endl;

    return 0;
}
