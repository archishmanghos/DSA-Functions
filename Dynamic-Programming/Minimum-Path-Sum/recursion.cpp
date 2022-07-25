#include <bits/stdc++.h>
using namespace std;

int dp(int posX, int posY, int n, int m, vector<vector<int>> &grid) {
    if (posX >= n or posY >= m) return 200200;
    if (posX == n - 1 and posY == m - 1) return grid[n - 1][m - 1];

    int ans = min(dp(posX, posY + 1, n, m, grid), dp(posX + 1, posY, n, m, grid)) + grid[posX][posY];
    return ans;
}

int32_t main() {

    int n, m; cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    cout << dp(0, 0, n, m, grid);
    return 0;
}