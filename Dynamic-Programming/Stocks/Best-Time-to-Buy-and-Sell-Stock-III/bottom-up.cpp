#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int n; cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) cin >> prices[i];

    vector<vector<vector<int>>> cache(n, vector<vector<int>>(2, vector<int>(3, 0)));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= 1; j++) {
            for (int k = 2; k >= 0; k--) {
                if (k == 2) cache[i][j][k] = 0;
                else if (i == n - 1) {
                    cache[i][j][k] = (j ? 0 : prices[i]);
                } else {
                    if (j) {
                        cache[i][j][k] = max(cache[i + 1][0][k] - prices[i], cache[i + 1][1][k]);
                    } else {
                        cache[i][j][k] = max(cache[i + 1][1][k + 1] + prices[i], cache[i + 1][0][k]);
                    }
                }
            }
        }
    }

    cout << cache[0][1][0];
    return 0;
}