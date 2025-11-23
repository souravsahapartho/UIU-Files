
#include <bits/stdc++.h>
using namespace std;

bool dfs(int i, int j, vector<vector<int>> &maze, vector<vector<bool>> &visited, vector<pair<int,int>> &path) {
    int n = maze.size(), m = maze[0].size();
    if (i < 0 || j < 0 || i >= n || j >= m) return false;
    if (maze[i][j] == 0 || visited[i][j]) return false;
    path.push_back({i, j});
    visited[i][j] = true;
    if (i == n - 1 && j == m - 1) return true;
    vector<int> dx = {1, 0, 0, -1};
    vector<int> dy = {0, 1, -1, 0};
    for (int dir = 0; dir < 4; dir++) {
        int ni = i + dx[dir], nj = j + dy[dir];
        if (dfs(ni, nj, maze, visited, path)) return true;
    }
    path.pop_back();
    return false;
}

int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {0, 1, 1, 1}
    };
    vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));
    vector<pair<int,int>> path;
    if (dfs(0, 0, maze, visited, path)) {
        cout << "Path from (0,0) to (3,3): ";
        for (int i = 0; i < path.size(); i++) {
            cout << "(" << path[i].first << ", " << path[i].second << ")";
            if (i != path.size() - 1) cout << ", ";
        }
    } else {
        cout << "No path found";
    }
    return 0;
}
