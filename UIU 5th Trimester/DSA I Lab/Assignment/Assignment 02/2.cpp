#include <bits/stdc++.h>
using namespace std;

int n, ans = INT_MAX;
vector<vector<int>> cost;
vector<bool> vis;

void dfs(int city, int count, int total) {
    if (count == n && cost[city][0]) {
        ans = min(ans, total + cost[city][0]);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i] && cost[city][i]) {
            vis[i] = true;
            dfs(i, count + 1, total + cost[city][i]);
            vis[i] = false;
        }
    }
}

int main() {
    cout << "Enter N: ";
    cin >> n;

    cost = vector<vector<int>>(n, vector<int>(n));
    vis = vector<bool>(n, false);

    cout << "Enter cost matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];

    vis[0] = true;
    dfs(0, 1, 0);

    cout << "Minimum cost: " << ans << endl;
}
