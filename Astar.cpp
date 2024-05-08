#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Node {
    Node* parent;
    pair<int, int> position;
    int g, h, f;

    Node(Node* parent, pair<int, int> position) : parent(parent), position(position), g(0), h(0), f(0) {}

    bool operator==(const Node& other) const {
        return position == other.position;
    }
};

class AStar {
public:
    AStar(vector<vector<int>>& maze) : maze(maze) {}

    vector<pair<int, int>> search(pair<int, int> start, pair<int, int> end) {
        Node* startNode = new Node(nullptr, start);
        startNode->g = startNode->h = startNode->f = 0;
        Node* endNode = new Node(nullptr, end);
        endNode->g = endNode->h = endNode->f = 0;

        priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> openList;
        vector<Node*> closedList;

        openList.push({0, startNode});

        while (!openList.empty()) {
            Node* currentNode = openList.top().second;
            openList.pop();
            closedList.push_back(currentNode);

            if (*currentNode == *endNode) {
                vector<pair<int, int>> path;
                while (currentNode != nullptr) {
                    path.push_back(currentNode->position);
                    currentNode = currentNode->parent;
                }
                reverse(path.begin(), path.end());
                return path;
            }

            vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
            vector<Node*> children;
            for (const auto& dir : directions) {
                pair<int, int> newPos = {currentNode->position.first + dir.first, currentNode->position.second + dir.second};
                if (isValid(newPos)) {
                    Node* newNode = new Node(currentNode, newPos);
                    children.push_back(newNode);
                }
            }

            for (Node* child : children) {
                for (Node* closedChild : closedList) {
                    if (*child == *closedChild) {
                        continue;
                    }
                }

                child->g = currentNode->g + 1;
                child->h = (child->position.first - endNode->position.first) * (child->position.first - endNode->position.first) +
                           (child->position.second - endNode->position.second) * (child->position.second - endNode->position.second);
                child->f = child->g + child->h;

                for (auto& openNode : openList) {
                    if (*child == *(openNode.second) && child->g > openNode.second->g) {
                        continue;
                    }
                }

                openList.push({child->f, child});
            }
        }

        return {}; // No path found
    }

private:
    vector<vector<int>>& maze;

    bool isValid(pair<int, int> pos) {
        return pos.first >= 0 && pos.first < maze.size() && pos.second >= 0 && pos.second < maze[0].size() && maze[pos.first][pos.second] == 0;
    }
};

int main() {
    vector<vector<int>> maze = {
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    AStar astar(maze);
    pair<int, int> start = {0, 0};
    pair<int, int> end = {7, 6};

    vector<pair<int, int>> path = astar.search(start, end);

    if (!path.empty()) {
        cout << "Path found:" << endl;
        for (auto& p : path) {
            cout << "(" << p.first << ", " << p.second << ")" << endl;
        }
    } else {
        cout << "No path found." << endl;
    }

    return 0;
}
