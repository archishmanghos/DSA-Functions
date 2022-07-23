#include <bits/stdc++.h>
using namespace std;

int dp(int index, vector<int> &nums, vector<int> &cache) {
    if (index <= 0) return index == 0 ? nums[index] : 0;
    if (cache[index] != -1) return cache[index];

    int ans = max(dp(index - 2, nums, cache) + nums[index], dp(index - 1, nums, cache));

    return cache[index] = ans;
}

int32_t main() {

    int n; cin >> n;
    vector<int> nums(n), cache(n, -1);
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << dp(n - 1, nums, cache);
    return 0;
}