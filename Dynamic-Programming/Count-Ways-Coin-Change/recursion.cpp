#include <bits/stdc++.h>
using namespace std;

int dp(int index, int amount, int n, vector<int> &coins) {
    if (amount == 0) return 1;
    if (index == n - 1) {
        return (amount % coins[index] == 0);
    }

    int ans = dp(index + 1, amount, n, coins);
    if (coins[index] <= amount) {
        ans += dp(index, amount - coins[index], n, coins);
    }

    return ans;
}

int32_t main() {

    int n, amount; cin >> n >> amount;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    cout << dp(0, amount, n, coins);
    return 0;
}