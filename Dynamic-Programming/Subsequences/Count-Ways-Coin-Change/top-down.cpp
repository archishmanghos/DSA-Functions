#include <bits/stdc++.h>
using namespace std;

int dp(int index, int amount, int n, vector<int> &coins, vector<vector<int>> &cache) {
    if (amount == 0) return 1;
    if (index == n - 1) {
        return (amount % coins[index] == 0);
    }
    if (cache[index][amount] != -1) return cache[index][amount];

    int ans = dp(index + 1, amount, n, coins, cache);
    if (coins[index] <= amount) {
        ans += dp(index, amount - coins[index], n, coins, cache);
    }

    return cache[index][amount] = ans;
}

int32_t main() {

    int n, amount; cin >> n >> amount;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    vector<vector<int>> cache(n, vector<int>(amount + 1, -1));
    cout << dp(0, amount, n, coins, cache);
    return 0;
}