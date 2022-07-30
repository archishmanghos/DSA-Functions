#include <bits/stdc++.h>
using namespace std;

int dp(int index, int length, int n, vector<int> &price, vector<vector<int>> &cache) {
    if (index == n - 1) {
        if (length % n == 0) return (length / n) * price[index];
        return 0;
    }
    if (cache[index][length] != -1) return cache[index][length];

    int ans = dp(index + 1, length, n, price, cache);
    if ((index + 1) <= length) {
        ans = max(ans, dp(index, length - (index + 1), n, price, cache) + price[index]);
    }

    return cache[index][length] = ans;
}

int32_t main() {

    int n; cin >> n;
    vector<int> price(n);
    for (int i = 0; i < n; i++) cin >> price[i];

    vector<vector<int>> cache(n, vector<int>(n + 1, -1));
    cout << dp(0, n, n, price, cache);
    return 0;
}