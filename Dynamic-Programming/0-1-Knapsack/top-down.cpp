#include <bits/stdc++.h>
using namespace std;

int dp(int index, int weightRem, int n, vector<int> &weight, vector<int> &value, vector<vector<int>> &cache) {
    if (index == n - 1) {
        if (weight[index] <= weightRem) return value[index];
        return 0;
    }
    if (cache[index][weightRem] != -1) return cache[index][weightRem];

    int take = 0, notTake = dp(index + 1, weightRem, n, weight, value, cache);
    if (weight[index] <= weightRem) {
        take = dp(index + 1, weightRem - weight[index], n, weight, value, cache) + value[index];
    }

    return cache[index][weightRem] = max(take, notTake);
}

int32_t main() {

    int n, w; cin >> n >> w;
    vector<int> weight(n), value(n);
    for (int i = 0; i < n; i++) cin >> weight[i] >> value[i];
    vector<vector<int>> cache(n, vector<int>(w + 1, -1));

    cout << dp(0, w, n, weight, value, cache);
    return 0;
}