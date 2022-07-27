#include <bits/stdc++.h>
using namespace std;

int dp(int posX, int posY1, int posY2, int n, int m, vector<vector<int>> &grid) {
    if (posY1 < 0 or posY2 < 0 or posY1 == m or posY2 == m) return 0;
    if (posX == n - 1) return (posY1 == posY2 ? grid[posX][posY1] : grid[posX][posY1] + grid[posX][posY2]);

    int ans = 0, dy[3] = { -1, 0, 1};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ans = max(ans, dp(posX + 1, posY1 + dy[i], posY2 + dy[j], n, m, grid) + (posY1 == posY2 ? grid[posX][posY1] : grid[posX][posY1] + grid[posX][posY2]));
        }
    }

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

    cout << dp(0, 0, m - 1, n, m, grid);
    return 0;
}