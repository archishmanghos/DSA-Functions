#include <bits/stdc++.h>
using namespace std;

int dp(int index, int preTrain, int n, vector<vector<int>> &points) {
    if (index >= n) return 0;

    int ans = 0;
    for (int i = 0; i < 3; i++) {
        if (index > 0) {
            if (i != preTrain) {
                ans = max(ans, dp(index + 1, i, n, points) + points[index][i]);
            }
        } else {
            ans = max(ans, dp(index + 1, i, n, points) + points[index][i]);
        }
    }

    return ans;
}

int32_t main() {

    int n; cin >> n;
    vector<vector<int>> points(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> points[i][j];
        }
    }

    cout << dp(0, 0, n, points);
    return 0;
}