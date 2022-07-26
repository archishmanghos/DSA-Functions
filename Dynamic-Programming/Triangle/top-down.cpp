#include <bits/stdc++.h>
using namespace std;

int dp(int posX, int posY, int &n, int &m, vector<vector<int>> &triangle, vector<vector<int>> &cache) {
    if (posX == n - 1) return triangle[posX][posY];
    if (cache[posX][posY] != -1) return cache[posX][posY];

    m += 1;
    int ans = min(dp(posX + 1, posY, n, m, triangle, cache), dp(posX + 1, posY + 1, n, m, triangle, cache)) + triangle[posX][posY];
    return cache[posX][posY] = ans;
}

int32_t main() {

    int n; cin >> n;
    vector<vector<int>> triangle(n);
    for (int i = 0; i < n; i++) {
        vector<int> temp(i + 1);
        for (int j = 0; j <= i; j++) {
            cin >> temp[j];
        }
        triangle[i] = temp;
    }

    int m = 1;
    vector<vector<int>> cache(n, vector<int> (n, -1));
    cout << dp(0, 0, n, m, triangle, cache);
    return 0;
}