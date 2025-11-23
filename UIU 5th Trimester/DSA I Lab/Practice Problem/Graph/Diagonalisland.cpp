#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<char>> &M, int r, int c, vector<vector<bool>> &visited) {
    int ROW = M.size();
    int COL = M[0].size();
    return (r >= 0) && (r < ROW) &&
           (c >= 0) && (c < COL) &&
           (M[r][c] == '1' && !visited[r][c]);
}

void DFS(vector<vector<char>> &M, int r, int c, vector<vector<bool>> &visited) {
    vector<int> rNbr = {-1, -1, 1, 1};
    vector<int> cNbr = {-1,  1, -1, 1};

    visited[r][c] = true;

    for (int k = 0; k < 4; ++k) {
        int newR = r + rNbr[k];
        int newC = c + cNbr[k];
        if (isSafe(M, newR, newC, visited)) {
            DFS(M, newR, newC, visited);
        }
    }
}

int countIslands(vector<vector<char>> &M) {
    int ROW = M.size();
    int COL = M[0].size();
    vector<vector<bool>> visited(ROW, vector<bool>(COL, false));
    int count = 0;

    for (int r = 0; r < ROW; ++r) {
        for (int c = 0; c < COL; ++c) {
            if (M[r][c] == '1' && !visited[r][c]) {
                DFS(M, r, c, visited);
                ++count;
            }
        }
    }
    return count;
}

int main() {
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','1','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    int result = countIslands(grid);
    cout << "Number of islands: " << result << endl;

    return 0;
}
