#include <bits/stdc++.h>
using namespace std;

bool dp(int index, int sum, int n, vector<int> &nums, vector<vector<int>> &cache) {
    if (sum == 0) return true;
    if (index == n - 1) return nums[index] == sum;
    if (cache[index][sum] != -1) return cache[index][sum];

    bool ans = dp(index + 1, sum, n, nums, cache);
    if (nums[index] <= sum) {
        ans |= dp(index + 1, sum - nums[index], n, nums, cache);
    }

    return cache[index][sum] = ans;
}

int32_t main() {

    int n, sum = 0; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        sum += nums[i];
    }

    if (sum % 2) return false;
    vector<vector<int>> cache(n, vector<int>(sum, -1));
    sum >>= 1;

    cout << dp(0, sum, n, nums, cache);
    return 0;
}