#include <bits/stdc++.h>
using namespace std;

int dp(int posX, int posY, int m, int n, vector<vector<int>> &cache) {
    if (posX >= m or posY >= n) return 0;
    if (posX == m - 1 and posY == n - 1) return 1;
    if (cache[posX][posY] != -1) return cache[posX][posY];

    int moveRight = dp(posX, posY + 1, m, n, cache);
    int moveLeft = dp(posX + 1, posY, m, n, cache);
    return cache[posX][posY] = moveLeft + moveRight;
}

int32_t main() {

    int n, m; cin >> m >> n;
    vector<vector<int>> cache(m, vector<int>(n, -1));
    cout << dp(0, 0, m, n, cache);

    return 0;
}