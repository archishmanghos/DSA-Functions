#include <bits/stdc++.h>
using namespace std;

int dp(int posX, int posY, int &n, int &m, vector<vector<int>> &triangle) {
    if (posX == n - 1) return triangle[posX][posY];

    m += 1;
    int ans = min(dp(posX + 1, posY, n, m, triangle), dp(posX + 1, posY + 1, n, m, triangle)) + triangle[posX][posY];
    return ans;
}

int32_t main() {

    int n, m = 1; cin >> n;
    vector<vector<int>> triangle(n);
    for (int i = 0; i < n; i++) {
        vector<int> temp(i + 1);
        for (int j = 0; j <= i; j++) {
            cin >> temp[j];
        }
        triangle[i] = temp;
    }

    cout << dp(0, 0, n, m, triangle);
    return 0;
}