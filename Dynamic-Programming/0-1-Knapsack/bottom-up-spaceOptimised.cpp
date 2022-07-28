#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int n, w; cin >> n >> w;
    vector<int> weight(n), value(n);
    for (int i = 0; i < n; i++) cin >> weight[i] >> value[i];
    vector<int> preCache(w + 1, 0), curCache(w + 1, 0);

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= w; j++) {
            if (i == n - 1) {
                curCache[j] = (weight[i] <= j ? value[i] : 0);
            } else {
                curCache[j] = preCache[j];
                if (weight[i] <= j) {
                    curCache[j] = max(curCache[j], preCache[j - weight[i]] + value[i]);
                }
            }
        }
        preCache = curCache;
    }

    cout << preCache[w];
    return 0;
}