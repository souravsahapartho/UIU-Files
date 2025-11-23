#include <bits/stdc++.h>
using namespace std;

bool dfs(int i, int j, vector<vector<char>> &grid, string &word, int index, vector<vector<bool>> &visited) {
    if (index == word.size()) return true;
    int n = grid.size(), m = grid[0].size();
    if (i < 0 || j < 0 || i >= n || j >= m) return false;
    if (visited[i][j] || grid[i][j] != word[index]) return false;
    visited[i][j] = true;
    vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int dir = 0; dir < 8; dir++) {
        if (dfs(i + dx[dir], j + dy[dir], grid, word, index + 1, visited)) {
            return true;
        }
    }
    visited[i][j] = false;
    return false;
}

int main() {
    vector<vector<char>> grid = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word = "ABCCED";
    int n = grid.size(), m = grid[0].size();
    bool found = false;
    for (int i = 0; i < n && !found; i++) {
        for (int j = 0; j < m && !found; j++) {
            vector<vector<bool>> visited(n, vector<bool>(m, false));
            if (dfs(i, j, grid, word, 0, visited)) {
                found = true;
            }
        }
    }
    if (found) cout << "Word '" << word << "' exists in the grid";
    else cout << "Word '" << word << "' does not exist in the grid";
    return 0;
}
