#include <bits/stdc++.h>
using namespace std;

int dp(int index1, int index2, int n, int m, string &s, string &t) {
    if (index1 == n or index2 == m) {
        return index2 == m;
    }

    int ans;
    if (s[index1] == t[index2]) {
        ans = dp(index1 + 1, index2 + 1, n, m, s, t) + dp(index1 + 1, index2, n, m, s, t);
    } else {
        ans = dp(index1 + 1, index2, n, m, s, t);
    }

    return ans;
}

int32_t main() {

    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();

    cout << dp(0, 0, n, m, s, t);
    return 0;
}