#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();

    vector<vector<int>> cache(n + 1, vector<int>(m + 1, 0));
    for (int i = n; i >= 0; i--) {
        for (int j = m; j >= 0; j--) {
            if (i == n or j == m) {
                if (i == n) cache[i][j] = m - j;
                else cache[i][j] = n - i;
            } else {
                if (s[i] == t[j]) {
                    cache[i][j] = cache[i + 1][j + 1];
                } else {
                    cache[i][j] = 1 + min(cache[i + 1][j + 1], min(cache[i + 1][j], cache[i][j + 1]));
                }
            }
        }
    }

    cout << cache[0][0];
    return 0;
}