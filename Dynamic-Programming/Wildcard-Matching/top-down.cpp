#include <bits/stdc++.h>
using namespace std;

bool dp(int index1, int index2, int n, int m, string &s, string &t, vector<vector<int>> &cache) {
    if (index1 == n or index2 == m) {
        if (index1 == n) {
            if (index2 == m) return true;
            while (index2 < m) {
                if (t[index2] != '*') return false;
                index2++;
            }
            return true;
        }
        return false;
    }
    if (cache[index1][index2] != -1) return cache[index1][index2];

    bool ans = false;
    if (s[index1] == t[index2] or t[index2] == '?') {
        ans = dp(index1 + 1, index2 + 1, n, m, s, t, cache);
    } else {
        if (t[index2] == '*') {
            ans = dp(index1 + 1, index2, n, m, s, t, cache) | dp(index1, index2 + 1, n, m, s, t, cache);
        }
    }

    return cache[index1][index2] = ans;
}

int32_t main() {

    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();

    vector<vector<int>> cache(n, vector<int>(m, -1));
    cout << dp(0, 0, n, m, s, t, cache);
    return 0;
}