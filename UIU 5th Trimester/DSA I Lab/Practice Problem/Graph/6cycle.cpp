
#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &recStack) {
    visited[node] = true;
    recStack[node] = true;
    for (int i = 0; i < graph[node].size(); i++) {
        int neighbor = graph[node][i];
        if (!visited[neighbor]) {
            if (dfs(neighbor, graph, visited, recStack)) return true;
        } else if (recStack[neighbor]) {
            return true;
        }
    }
    recStack[node] = false;
    return false;
}

int main() {
    vector<vector<int>> edges = {{0,1}, {1,2}, {2,0}};
    int n = 3;
    vector<vector<int>> graph(n);
    for (auto e : edges) {
        graph[e[0]].push_back(e[1]);
    }
    vector<bool> visited(n, false), recStack(n, false);
    bool hasCycle = false;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dfs(i, graph, visited, recStack)) {
            hasCycle = true;
            break;
        }
    }
    if (hasCycle) cout << "The graph contains a cycle";
    else cout << "The graph does not contain a cycle";
    return 0;
}
