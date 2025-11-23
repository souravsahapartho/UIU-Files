#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(int n, vector<vector<int>> &graph) {
    vector<int> indegree(n, 0), order;
    for (int u = 0; u < n; u++) {
        for (int v : graph[u]) {
            indegree[v]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : graph[u]) {
            indegree[v]--;
            if (indegree[v] == 0) q.push(v);
        }
    }
    return order;
}

int main() {
    int n = 4;
    vector<vector<int>> graph(n);
    vector<pair<int,int>> edges = {{0,1}, {0,2}, {1,3}, {2,3}};
    for (auto e : edges) graph[e.first].push_back(e.second);
    vector<int> order = topologicalSort(n, graph);
    cout << "Topological sort: ";
    for (int i = 0; i < order.size(); i++) {
        cout << order[i];
        if (i != order.size() - 1) cout << ", ";
    }
    return 0;
}
