#include <bits/stdc++.h>
using namespace std;

int dp(int posX, int posY, int m, int n, vector< vector< int> > &obstacleGrid, vector<vector<long>> &cache) {
    if (posX >= m or posY >= n) return 0;
    if (obstacleGrid[posX][posY] == -1) return 0;
    if (posX == m - 1 and posY == n - 1) return 1;
    if (cache[posX][posY] != -1) return cache[posX][posY];

    long down = dp(posX + 1, posY, m, n, obstacleGrid, cache);
    long right = dp(posX, posY + 1, m, n, obstacleGrid, cache);
    return cache[posX][posY] = down + right;
}

int32_t main() {

    int n, m; cin >> m >> n;
    vector<vector<int>> obstacleGrid(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> obstacleGrid[i][j];
        }
    }

    vector<vector<long>> cache(m + 1, vector<long>(n + 1, -1));
    cout << dp(0, 0, m, n, obstacleGrid, cache);
    return 0;
}