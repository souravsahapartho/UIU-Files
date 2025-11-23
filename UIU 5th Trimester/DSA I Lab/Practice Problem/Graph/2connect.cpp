#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &graph, vector<bool> &visited) {
    visited[node] = true;
    for (int i = 0; i < graph.size(); i++) {
        if (graph[node][i] && !visited[i]) {
            dfs(i, graph, visited);
        }
    }
}

int main() {
    vector<vector<int>> graph = {
        {0, 1, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {0, 0, 1, 0}
    };
    int n = graph.size();
    vector<bool> visited(n, false);
    dfs(0, graph, visited);
    bool connected = all_of(visited.begin(), visited.end(), [](bool v) { return v; });
    if (connected) cout << "The graph is connected";
    else cout << "The graph is not connected";
    return 0;
}
