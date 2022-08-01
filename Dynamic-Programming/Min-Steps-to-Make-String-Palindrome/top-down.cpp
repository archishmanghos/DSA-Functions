#include <bits/stdc++.h>
using namespace std;

int dp(int index1, int index2, int n, string &s, vector<vector<int>> &cache) {
    if (index1 >= index2) return 0;
    int &ans = cache[index1][index2];
    if (ans != -1) return ans;

    if (s[index1] == s[index2]) {
        ans = dp(index1 + 1, index2 - 1, n, s, cache);
    } else {
        ans = min(dp(index1 + 1, index2, n, s, cache) + 1, dp(index1, index2 - 1, n, s, cache) + 1);
    }

    return ans;
}

int32_t main() {

    string s; cin >> s;
    int n = s.size();

    vector<vector<int>> cache(n, vector<int>(n, -1));
    cout << dp(0, n - 1, n, s, cache);
    return 0;
}