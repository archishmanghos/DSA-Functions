#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int n; cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) cin >> prices[i];

    vector<vector<int>> cache(n + 1, vector<int>(2, 0));
    for (int i = n; i >= 0; i--) {
        for (int j = 0; j <= 1; j++) {
            if (i == n) cache[i][j] = 0;
            else if (i == n - 1) {
                cache[i][j] = j ? 0 : prices[i];
            } else {
                if (j) {
                    cache[i][j] = max(cache[i + 1][0] - prices[i], cache[i + 1][1]);
                } else {
                    cache[i][j] = max(cache[i + 2][1] + prices[i], cache[i + 1][0]);
                }
            }
        }
    }

    cout << cache[0][1];
    return 0;
}