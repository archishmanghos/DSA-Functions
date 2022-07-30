#include <bits/stdc++.h>
using namespace std;

int dp(int index, int W, int n, vector<int> &profit, vector<int> &weight, vector<vector<int>> &cache) {
    if (W == 0) return 0;
    if (index == n - 1) {
        return ((W / weight[index]) * profit[index]);
    }
    if (cache[index][W] != -1) return cache[index][W];

    int ans = dp(index + 1, W, n, profit, weight, cache);
    if (weight[index] <= W) {
        ans = max(ans, dp(index, W - weight[index], n, profit, weight, cache) + profit[index]);
    }

    return cache[index][W] = ans;
}

int32_t main() {

    int n, w; cin >> n >> w;
    vector<int> profit(n), weight(n);
    for (int i = 0; i < n; i++) cin >> profit[i];
    for (int i = 0; i < n; i++) cin >> weight[i];

    vector<vector<int>> cache(n, vector<int>(w + 1, -1));
    cout << dp(0, w, n, profit, weight, cache);
    return 0;
}