#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) cin >> prices[i];

    vector<int> curCache(2, 0);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= 1; j++) {
            if (i == n - 1) {
                if (j) curCache[j] = 0;
                else curCache[j] = prices[i];
            } else {
                if (j) curCache[j] = max(curCache[0] - prices[i], curCache[1]);
                else curCache[j] = max(curCache[1] + prices[i], curCache[0]);
            }
        }
    }

    cout << curCache[1];
    return 0;
}