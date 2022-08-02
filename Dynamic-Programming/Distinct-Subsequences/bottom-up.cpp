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

    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size(), mod = 1e9 + 7;

    vector<vector<int>> cache(n + 1, vector<int>(m + 1, 0));
    for (int i = n; i >= 0; i--) {
        for (int j = m; j >= 0; j--) {
            if (i == n or j == m) {
                cache[i][j] = j == m;
            } else {
                if (s[i] == t[j]) {
                    cache[i][j] = (cache[i + 1][j + 1] % mod + cache[i + 1][j] % mod) % mod;
                } else {
                    cache[i][j] = cache[i + 1][j];
                }
            }
        }
    }

    cout << cache[0][0];
    return 0;
}