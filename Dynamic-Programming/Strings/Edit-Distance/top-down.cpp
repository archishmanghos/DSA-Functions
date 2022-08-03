#include <bits/stdc++.h>
using namespace std;

int dp(int index1, int index2, int n, int m, string &s, string &t, vector<vector<int>> &cache) {
    if (index1 == n or index2 == m) {
        if (index1 == n) return m - index2;
        return n - index1;
    }

    int &ans = cache[index1][index2];
    if (ans != -1) return ans;

    if (s[index1] == t[index2]) {
        ans = dp(index1 + 1, index2 + 1, n, m, s, t, cache);
    } else {
        ans = min(dp(index1 + 1, index2 + 1, n, m, s, t, cache), min(dp(index1, index2 + 1, n, m, s, t, cache), dp(index1 + 1, index2, n, m, s, t, cache))) + 1;
    }

    return ans;
}

int32_t main() {

    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();

    vector<vector<int>> cache(n, vector<int>(m, -1));
    cout << dp(0, 0, n, m, s, t, cache);
    return 0;
}