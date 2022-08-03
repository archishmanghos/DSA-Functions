#include <bits/stdc++.h>
using namespace std;

int dp(int index, int buy, int transactionCnt, int n, vector<int> &prices, vector<vector<vector<int>>> &cache) {
    if (transactionCnt == 2) return 0;
    if (index == n - 1) {
        if (buy) return 0;
        else return prices[n - 1];
    }

    int &profit = cache[index][buy][transactionCnt];
    if (profit != -1) return profit;

    if (buy) {
        profit = max(dp(index + 1, 0, transactionCnt, n, prices, cache) - prices[index], dp(index + 1, 1, transactionCnt, n, prices, cache));
    } else {
        profit = max(dp(index + 1, 1, transactionCnt + 1, n, prices, cache) + prices[index], dp(index + 1, 0, transactionCnt, n, prices, cache));
    }

    return profit;
}

int32_t main() {

    int n; cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) cin >> prices[i];

    vector<vector<vector<int>>> cache(n, vector<vector<int>>(2, vector<int>(2, -1)));
    cout << dp(0, 1, 0, n, prices, cache);
    return 0;
}