#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

int dp(int index, int buy, int n, vector<int> &prices) {
    if (index == n - 1) {
        if (buy) return 0;
        else return prices[n - 1];
    }

    int profit;
    if (buy) {
        profit = max(dp(index + 1, 0, n, prices) - prices[index], dp(index + 1, 1, n, prices));
    } else {
        profit = max(dp(index + 1, 1, n, prices) + prices[index], dp(index + 1, 0, n, prices));
    }

    return profit;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) cin >> prices[i];

    cout << dp(0, 1, n, prices);
    return 0;
}