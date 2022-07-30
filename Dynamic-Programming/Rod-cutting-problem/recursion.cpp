#include <bits/stdc++.h>
using namespace std;

int dp(int index, int length, int n, vector<int> &price) {
    if (index == n - 1) {
        if (length % n == 0) return (length / n) * price[index];
        return 0;
    }

    int ans = dp(index + 1, length, n, price);
    if ((index + 1) <= length) {
        ans = max(ans, dp(index, length - (index + 1), n, price) + price[index]);
    }

    return ans;
}

int32_t main() {

    int n; cin >> n;
    vector<int> price(n);
    for (int i = 0; i < n; i++) cin >> price[i];

    cout << dp(0, n, n, price);
    return 0;
}