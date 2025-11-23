#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> graph = {
        {0, 1, 0, 0},
        {1, 0, 1, 1},
        {0, 1, 0, 1},
        {0, 1, 1, 0}
    };
    int start = 0;
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<int> order;
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        order.push_back(node);
        for (int i = 0; i < n; i++) {
            if (graph[node][i] && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    cout << "Shortest path from " << start << ": [";
    for (int i = 0; i < order.size(); i++) {
        cout << order[i];
        if (i != order.size() - 1) cout << ", ";
    }
    cout << "]";
    return 0;
}
