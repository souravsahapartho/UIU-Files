#include <bits/stdc++.h>
using namespace std;

int findMinEdges(int start, int end, const vector<vector<int>>& graph) {
    vector<int> distance(graph.size(), -1);
    queue<int> q;
    distance[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : graph[current]) {
            if (distance[neighbor] == -1) {
                distance[neighbor] = distance[current] + 1;
                q.push(neighbor);
                if (neighbor == end) return distance[end];
            }
        }
    }

    return -1;
}

int main() {
    int V = 9;
    vector<vector<int>> graph(V);

    vector<pair<int, int>> edges = {
        {0, 1}, {0, 7}, {1, 7}, {1, 2}, {2, 3}, {2, 5}, {2, 8},
        {3, 4}, {3, 5}, {4, 5}, {5, 6}, {6, 7}, {7, 8}
    };

    for (auto [u, v] : edges) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout << "findMinEdges(0, 5): " << findMinEdges(0, 5, graph) << endl;
    cout << "findMinEdges(3, 8): " << findMinEdges(3, 8, graph) << endl;
    cout << "findMinEdges(2, 6): " << findMinEdges(2, 6, graph) << endl;

    return 0;
}
