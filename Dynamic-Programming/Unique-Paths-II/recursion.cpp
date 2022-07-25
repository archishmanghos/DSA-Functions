#include <bits/stdc++.h>
using namespace std;

long dp(int posX, int posY, int m, int n, vector< vector< int> > &mat, vector<vector<int>> &cache) {
    if (posX >= m or posY >= n) return 0;
    if (mat[posX][posY] == -1) return 0;
    if (posX == m - 1 and posY == n - 1) return 1;

    long down = dp(posX + 1, posY, m, n, mat, cache) % int(1e9 + 7);
    long right = dp(posX, posY + 1, m, n, mat, cache) % int(1e9 + 7);
    return (down + right);
}

int32_t main() {

    int n, m; cin >> m >> n;
    vector<vector<int>> mat(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    cout << dp(0, 0, m, n, mat);
    return 0;
}