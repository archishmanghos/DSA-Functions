#include <bits/stdc++.h>
using namespace std;

int dp(int index, int weightRem, int n, vector<int> &weight, vector<int> &value) {
    if (index == n - 1) {
        if (weight[index] <= weightRem) return value[index];
        return 0;
    }

    int take = 0, notTake = dp(index + 1, weightRem, n, weight, value);
    if (weight[index] <= weightRem) {
        take = dp(index + 1, weightRem - weight[index], n, weight, value) + value[index];
    }

    return max(take, notTake);
}

int32_t main() {

    int n, w; cin >> n >> w;
    vector<int> weight(n), value(n);
    for (int i = 0; i < n; i++) cin >> weight[i] >> value[i];

    cout << dp(0, w, n, weight, value);
    return 0;
}