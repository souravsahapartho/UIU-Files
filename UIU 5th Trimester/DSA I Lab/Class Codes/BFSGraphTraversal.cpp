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

void performBFS(vector<vector<int>> graph, int startNode)
{
    vector<bool> visited(totalNodes, false);
    queue<int> q;

    visited[startNode] = true;
    q.push(startNode);

    cout << "BFS Traversal: ";
    while (!q.empty())
    {
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";

        for (int neighbor : graph[currentNode])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

int main()
{
    vector<vector<int>> graph(totalNodes);

    addEdge(graph, 10, 20);
    addEdge(graph, 10, 30);
    addEdge(graph, 20, 40);
    addEdge(graph, 20, 50);
    addEdge(graph, 30, 60);

    printGraph(graph);
    performBFS(graph, 10);

    return 0;
}
