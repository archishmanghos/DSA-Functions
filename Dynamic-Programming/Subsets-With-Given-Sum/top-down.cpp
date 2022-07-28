#include <bits/stdc++.h>
using namespace std;

int dp(int index, int sum, int n, vector<int> &num, vector<vector<int>> &cache) {
    if (sum == 0) return 1;
    if (index == n - 1) return num[n - 1] == sum;
    if (cache[index][sum] != -1) return cache[index][sum];

    int ans = dp(index + 1, sum, n, num, cache);
    if (num[index] <= sum) {
        ans += dp(index + 1, sum - num[index], n, num, cache);
    }

    return cache[index][sum] = ans;
}

int32_t main() {

    int n, k; cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    vector<vector<int>> cache(n, vector<int>(k + 1, -1));
    cout << dp(0, k, n, nums, cache);
    return 0;
}