#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int n, ans = 100100; cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<vector<int>> cache(n, vector<int>(n, 100100));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (i == n - 1) cache[i][j] = matrix[i][j];
            else {
                for (int k = 0; k < 3; k++) {
                    int newY = j + dy[k];
                    if (newY >= 0 and newY < n) {
                        cache[i][j] = min(cache[i][j], cache[i + 1][newY] + matrix[i][j]);
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        ans = min(ans, cache[0][i]);
    }

    cout << ans;
    return 0;
}