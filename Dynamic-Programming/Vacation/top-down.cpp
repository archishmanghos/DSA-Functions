#include <bits/stdc++.h>
using namespace std;

int dp(int index, int preTrain, int n, vector<vector<int>> &points, vector<vector<int>> &cache) {
    if (index >= n) return 0;
    if (cache[index][preTrain] != -1) return cache[index][preTrain];

    int ans = 0;
    for (int i = 0; i < 3; i++) {
        if (index > 0) {
            if (i != preTrain) {
                ans = max(ans, dp(index + 1, i, n, points, cache) + points[index][i]);
            }
        } else {
            ans = max(ans, dp(index + 1, i, n, points, cache) + points[index][i]);
        }
    }

    return cache[index][preTrain] = ans;
}

int32_t main() {

    int n; cin >> n;
    vector<vector<int>> points(n, vector<int>(3));
    vector<vector<int>> cache(n, vector<int>(3, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> points[i][j];
        }
    }

    cout << dp(0, 0, n, points, cache);
    return 0;
}