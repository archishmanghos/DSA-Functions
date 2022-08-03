#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int n, m; cin >> m >> n;
    vector<vector<int>> obstacleGrid(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> obstacleGrid[i][j];
        }
    }

    vector<vector<long>> cache(m + 1, vector<long>(n + 1, 0));
    cache[m - 1][n - 1] = 1;
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (i == m - 1 and j == n - 1) continue;
            if (obstacleGrid[i][j] != -1) {
                cache[i][j] = cache[i + 1][j] + cache[i][j + 1];
            }
        }
    }

    cout << cache[0][0];
    return 0;
}