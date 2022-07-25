#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int n, m; cin >> m >> n;
    vector<vector<int>> cache(m + 1, vector<int>(n + 1, 0));
    cache[m - 1][n - 1] = 1;
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (i == m - 1 and j == n - 1) continue;
            cache[i][j] = cache[i][j + 1] + cache[i + 1][j];
        }
    }

    cout << cache[0][0];
    return 0;
}