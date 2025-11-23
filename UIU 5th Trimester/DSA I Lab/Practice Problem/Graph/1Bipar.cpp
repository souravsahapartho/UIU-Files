#include <bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, -1);
    vector<int> customQueue(n * n);
    int front, rear;

    for (int start = 0; start < n; ++start) {
        if (color[start] == -1) {
            front = rear = 0;
            customQueue[rear++] = start;
            color[start] = 0;

            while (front < rear) {
                int node = customQueue[front++];
                for (int i = 0; i < n; ++i) {
                    if (graph[node][i]) {
                        if (color[i] == -1) {
                            color[i] = 1 - color[node];
                            customQueue[rear++] = i;
                        } else if (color[i] == color[node]) {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    if (isBipartite(graph)) cout << "The graph is bipartite\n";
    else cout << "The graph is not bipartite\n";
    return 0;
}
