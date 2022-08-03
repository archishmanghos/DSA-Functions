#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) cin >> prices[i];

    vector<vector<int>> cache(n, vector<int>(2, 0));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= 1; j++) {
            if (i == n - 1) {
                if (j) cache[i][j] = 0;
                else cache[i][j] = prices[i];
            } else {
                if (j) cache[i][j] = max(cache[i + 1][0] - prices[i], cache[i + 1][1]);
                else cache[i][j] = max(cache[i + 1][1] + prices[i], cache[i + 1][0]);
            }
        }
    }

    cout << cache[0][1];
    return 0;
}