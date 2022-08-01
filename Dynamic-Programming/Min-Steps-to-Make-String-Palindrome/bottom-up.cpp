#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    string s; cin >> s;
    int n = s.size();

    vector<vector<int>> cache(n + 1, vector<int>(n + 1, 0));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if (i >= j) cache[i][j] = 0;
            else {
                if (s[i] == s[j]) {
                    cache[i][j] = cache[i + 1][j - 1];
                } else {
                    cache[i][j] = min(cache[i + 1][j] + 1, cache[i][j - 1] + 1);
                }
            }
        }
    }

    cout << cache[0][n - 1];
    return 0;
}