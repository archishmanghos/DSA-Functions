#include <bits/stdc++.h>
using namespace std;

int dp(int amount, int n, vector<int> &coins) {
    if (amount == 0) return 0;

    int ans = 10001000;
    for (int i = 0; i < n; i++) {
        if (coins[i] <= amount) {
            ans = min(ans, dp(amount - coins[i], n, coins) + 1);
        }
    }

    return ans;
}

int32_t main() {

    int n, x; cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    int ans = dp(x, n, coins);
    if (ans == 10001000) cout << -1;
    else cout << ans;

    return 0;
}