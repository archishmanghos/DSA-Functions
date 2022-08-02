#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size(), mod = 1e9 + 7;

    vector<int> preCache(m + 1, 0), curCache(m + 1, 0);
    for (int i = n; i >= 0; i--) {
        for (int j = m; j >= 0; j--) {
            if (i == n or j == m) {
                curCache[j] = j == m;
            } else {
                if (s[i] == t[j]) {
                    curCache[j] = (preCache[j + 1] % mod + preCache[j] % mod) % mod;
                } else {
                    curCache[j] = preCache[j];
                }
            }
        }
        preCache = curCache;
    }

    cout << curCache[0];
    return 0;
}