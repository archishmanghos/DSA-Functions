#include <bits/stdc++.h>
using namespace std;

int dp(int index, int buy, int n, vector<int> &prices, vector<vector<int>> &cache) {
    if (index == n) return 0;
    if (index == n - 1) {
        if (buy) return 0;
        else return prices[n - 1];
    }

    int &profit = cache[index][buy];
    if (profit != -1) return cache[index][buy];

    if (buy) {
        profit = max(dp(index + 1, 0, n, prices, cache) - prices[index], dp(index + 1, 1, n, prices, cache));
    } else {
        profit = max(dp(index + 2, 1, n, prices, cache) + prices[index], dp(index + 1, 0, n, prices, cache));
    }

    return profit;
}

int32_t main() {

    int n; cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) cin >> prices[i];

    vector<vector<int>> cache(n, vector<int>(2, -1));
    cout << dp(0, 1, n, prices, cache);
    return 0;
}