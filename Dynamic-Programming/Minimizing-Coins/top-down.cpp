#include <bits/stdc++.h>
using namespace std;

int dp(int amount, int n, vector<int> &coins, vector<int> &cache) {
    if (amount == 0) return 0;
    if (cache[amount] != -1) return cache[amount];

    int ans = 10001000;
    for (int i = 0; i < n; i++) {
        if (coins[i] <= amount) {
            ans = min(ans, dp(amount - coins[i], n, coins, cache) + 1);
        }
    }

    return cache[amount] = ans;
}

int32_t main() {

    int n, x; cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    vector<int> cache(x + 1, -1);
    int ans = dp(x, n, coins, cache);
    if (ans == 10001000) cout << -1;
    else cout << ans;

    return 0;
}