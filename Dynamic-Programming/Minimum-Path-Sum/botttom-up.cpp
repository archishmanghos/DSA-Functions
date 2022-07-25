#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int n, m; cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> cache(n + 1, vector<int> (m + 1, 200200));
    cache[n - 1][m - 1] = grid[n - 1][m - 1];

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (i == n - 1 and j == m - 1) continue;
            cache[i][j] = min(cache[i][j + 1], cache[i + 1][j]) + grid[i][j];
        }
    }

    cout << cache[0][0];
    return 0;
}