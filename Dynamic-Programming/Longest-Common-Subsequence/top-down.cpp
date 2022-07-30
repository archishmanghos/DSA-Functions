#include <bits/stdc++.h>
using namespace std;

int dp(int index1, int index2, int n, int m, string &s, string &t, vector<vector<int>> &cache) {
    if (index1 == n or index2 == m) return 0;
    if (cache[index1][index2] != -1) return cache[index1][index2];

    if (s[index1] == t[index2]) return cache[index1][index2] = 1 + dp(index1 + 1, index2 + 1, n, m, s, t, cache);
    return cache[index1][index2] = max(dp(index1 + 1, index2, n, m, s, t, cache), dp(index1, index2 + 1, n, m, s, t, cache));
}

int32_t main() {

    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();

    vector<vector<int>> cache(n, vector<int>(m, -1));
    cout << dp(0, 0, n, m, s, t, cache);
    return 0;
}