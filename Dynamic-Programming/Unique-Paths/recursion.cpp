#include <bits/stdc++.h>
using namespace std;

int dp(int posX, int posY, int m, int n) {
    if (posX >= m or posY >= n) return 0;
    if (posX == m - 1 and posY == n - 1) return 1;

    int moveRight = dp(posX, posY + 1, m, n);
    int moveLeft = dp(posX + 1, posY, m, n);
    return moveLeft + moveRight;
}

int32_t main() {

    int n, m; cin >> m >> n;
    cout << dp(0, 0, m, n);
    return 0;
}