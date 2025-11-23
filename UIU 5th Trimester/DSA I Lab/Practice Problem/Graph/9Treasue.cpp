#include <bits/stdc++.h>
using namespace std;

bool dfs(int i, int j, vector<vector<int>> &maze, vector<vector<bool>> &visited, vector<pair<int,int>> &path) {
    int n = maze.size(), m = maze[0].size();
    if (i < 0 || j < 0 || i >= n || j >= m) return false;
    if (maze[i][j] == 1 || visited[i][j]) return false;
    path.push_back({i, j});
    visited[i][j] = true;
    if (maze[i][j] == 999) return true;
    vector<int> dx = {0, 1, 0, -1};  // right, down, left, up
    vector<int> dy = {1, 0, -1, 0};
    for (int dir = 0; dir < 4; dir++) {
        int ni = i + dx[dir], nj = j + dy[dir];
        if (dfs(ni, nj, maze, visited, path)) return true;
    }
    path.pop_back();
    return false;
}

int main() {
    vector<vector<int>> maze = {
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {0, 1, 999, 0},
        {0, 0, 0, 1}
    };
    vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));
    vector<pair<int,int>> path;
    if (dfs(0, 0, maze, visited, path)) {
        cout << "Path to treasure: ";
        for (int i = 0; i < path.size(); i++) {
            cout << "(" << path[i].first << "," << path[i].second << ")";
            if (i != path.size() - 1) cout << ", ";
        }
    } else {
        cout << "No path to treasure found";
    }
    return 0;
}
