#include <bits/stdc++.h>
using namespace std;

int dp(int posX, int posY, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &cache) {
    if (posX >= n or posY >= m) return 200200;
    if (posX == n - 1 and posY == m - 1) return grid[n - 1][m - 1];
    if (cache[posX][posY] != -1) return cache[posX][posY];

    int ans = min(dp(posX, posY + 1, n, m, grid, cache), dp(posX + 1, posY, n, m, grid, cache)) + grid[posX][posY];
    return cache[posX][posY] = ans;
}

int32_t main() {

    int n, m; cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> cache(n, vector<int> (m, -1));
    cout << dp(0, 0, n, m, grid, cache);
    return 0;
}