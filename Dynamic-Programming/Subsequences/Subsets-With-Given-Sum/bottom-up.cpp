#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int n, k; cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    vector<vector<int>> cache(n, vector<int>(k + 1, 0));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= k; j++) {
            if (i == n - 1) {
                if (j == 0 and nums[i] == 0) cache[i][j] = 2;
                else cache[i][j] = (j == 0 or j == nums[i]);
            } else {
                cache[i][j] = cache[i + 1][j];
                if (nums[i] <= j) {
                    cache[i][j] += cache[i + 1][j - nums[i]];
                }
            }
        }
    }

    cout << cache[0][k];
    return 0;
}