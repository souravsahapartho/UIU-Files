#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<vector<int>> components;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            vector<int> component;
            stack<int> s;
            s.push(i);
            visited[i] = true;
            while (!s.empty()) {
                int node = s.top();
                s.pop();
                component.push_back(node);
                for (int j = 0; j < n; j++) {
                    if (graph[node][j] && !visited[j]) {
                        s.push(j);
                        visited[j] = true;
                    }
                }
            }
            components.push_back(component);
        }
    }
    cout << "Connected components: ";
    for (auto &comp : components) {
        for (int i = 0; i < comp.size(); i++) {
            cout << comp[i];
            if (i != comp.size() - 1) cout << ", ";
        }
        cout << " ";
    }
    return 0;
}
