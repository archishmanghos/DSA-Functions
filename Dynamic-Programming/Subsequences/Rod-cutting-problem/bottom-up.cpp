#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int n; cin >> n;
    vector<int> price(n);
    for (int i = 0; i < n; i++) cin >> price[i];

    vector<vector<int>> cache(n, vector<int>(n + 1, 0));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= n; j++) {
            if (i == n - 1) {
                if (j % n == 0) cache[i][j] = (j / n) * price[i];
            } else {
                cache[i][j] = cache[i + 1][j];
                if ((i + 1) <= j) {
                    cache[i][j] = max(cache[i][j], cache[i][j - (i + 1)] + price[i]);
                }
            }
        }
    }

    cout << cache[0][n];
    return 0;
}