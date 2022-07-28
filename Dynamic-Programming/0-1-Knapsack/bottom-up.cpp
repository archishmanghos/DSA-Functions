#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int n, w; cin >> n >> w;
    vector<int> weight(n), value(n);
    for (int i = 0; i < n; i++) cin >> weight[i] >> value[i];
    vector<vector<int>> cache(n, vector<int>(w + 1, 0));

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= w; j++) {
            if (i == n - 1) {
                cache[i][j] = (weight[i] <= j ? value[i] : 0);
            } else {
                cache[i][j] = cache[i + 1][j];
                if (weight[i] <= j) {
                    cache[i][j] = max(cache[i][j], cache[i + 1][j - weight[i]] + value[i]);
                }
            }
        }
    }

    cout << cache[0][w];
    return 0;
}