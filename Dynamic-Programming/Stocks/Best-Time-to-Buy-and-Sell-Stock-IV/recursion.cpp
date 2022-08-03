#include <bits/stdc++.h>
using namespace std;

int dp(int index, int transactionCnt, int n, int k, vector<int> &prices) {
    if (transactionCnt == 2 * k) return 0;
    if (index == n - 1) {
        if (transactionCnt % 2 == 0) return 0;
        else return prices[n - 1];
    }

    int profit;
    if (transactionCnt % 2 == 0) {
        profit = max(dp(index + 1, transactionCnt + 1, n, k, prices) - prices[index], dp(index + 1, transactionCnt, n, k, prices));
    } else {
        profit = max(dp(index + 1, transactionCnt + 1, n, k, prices) + prices[index], dp(index + 1, transactionCnt, n, k, prices));
    }

    return profit;
}

int32_t main() {

    int n, k; cin >> n >> k;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) cin >> prices[i];

    cout << dp(0, 0, n, k, prices);
    return 0;
}