#include <bits/stdc++.h>
using namespace std;

int dp(int posX, int posY, int n, vector<vector<int>>& matrix) {
    if (posY < 0 or posY == n) return 100100;
    if (posX == n - 1) return matrix[posX][posY];

    int dy[3] = { -1, 0, 1}, ans = 100100;
    for (int i = 0; i < 3; i++) {
        ans = min(ans, dp(posX + 1, posY + dy[i], n, matrix) + matrix[posX][posY]);
    }

    return ans;
}

int32_t main() {

    int n, ans = 100100; cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        ans = min(ans, dp(0, i, n, matrix));
    }

    cout << ans;
    return 0;
}