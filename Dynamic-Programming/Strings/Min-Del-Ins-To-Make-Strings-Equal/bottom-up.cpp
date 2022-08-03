#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();

    vector<vector<int>> cache(n + 1, vector<int>(m + 1, 0));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (s[i] == t[j]) {
                cache[i][j] = 1 + cache[i + 1][j + 1];
            } else {
                cache[i][j] = max(cache[i + 1][j], cache[i][j + 1]);
            }
        }
    }

    cout << (n + m) - 2 * cache[0][0];
    return 0;
}