#include <bits/stdc++.h>
using namespace std;

int dp(int index, int n, vector<int> &nums, vector<int> &cache) {
    if (index >= n) return 0;
    if (cache[index] != -1) return cache[index];

    int robThisHouse = dp(index + 2, n, nums, cache) + nums[index];
    int dontRobThisHouse = dp(index + 1, n, nums, cache);
    return cache[index] = max(robThisHouse, dontRobThisHouse);
}

int32_t main() {

    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    if (n == 1) return nums[0];
    vector<int> cache(n, -1);
    int ans = dp(0, n - 1, nums, cache);
    cache.assign(n, -1);
    ans = max(ans, dp(1, n, nums, cache));
    cout << ans;

    return 0;
}