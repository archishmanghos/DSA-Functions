#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int n, k; cin >> n >> k;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) cin >> prices[i];

    vector<vector<int>> cache(n, vector<int>(2 * k + 1, 0));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 2 * k; j >= 0; j--) {
            if (j == 2 * k) cache[i][j] = 0;
            else if (i == n - 1) {
                cache[i][j] = (j % 2 == 0 ? 0 : prices[i]);
            } else {
                if (j % 2 == 0) {
                    cache[i][j] = max(cache[i + 1][j + 1] - prices[i], cache[i + 1][j]);
                } else {
                    cache[i][j] = max(cache[i + 1][j + 1] + prices[i], cache[i + 1][j]);
                }
            }
        }
    }

    cout << cache[0][0];
    return 0;
}