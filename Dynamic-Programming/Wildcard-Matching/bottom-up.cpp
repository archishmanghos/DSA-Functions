#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();

    vector<vector<bool>> cache(n + 1, vector<bool>(m + 1, 0));
    for (int i = n; i >= 0; i--) {
        for (int j = m; j >= 0; j--) {
            if (i == n or j == m) {
                if (i == n) {
                    if (j == m) cache[i][j] = 1;
                    else {
                        int k = j, ok = 1;
                        while (k < m) {
                            if (t[k++] != '*') {
                                ok = 0;
                                break;
                            }
                        }
                        cache[i][j] = ok;
                    }
                }
            } else {
                if (s[i] == t[j] or t[j] == '?') {
                    cache[i][j] = cache[i + 1][j + 1];
                } else {
                    if (t[j] == '*') {
                        cache[i][j] = cache[i + 1][j] | cache[i][j + 1];
                    }
                }
            }
        }
    }

    cout << cache[0][0];
    return 0;
}