#include <bits/stdc++.h>
using namespace std;

int totalNodes = 100;

void addEdge(vector<vector<int>> &graph, int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void printGraph(const vector<vector<int>> &graph)
{
    cout << "Adjacency List:\n";
    for (int i = 0; i < graph.size(); i++)
    {
        if (!graph[i].empty())
        {
            cout << i << ": ";
            for (int neighbor : graph[i])
            {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
}

int main()
{
    vector<vector<int>> graph(totalNodes);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);

    printGraph(graph);

    return 0;
}
