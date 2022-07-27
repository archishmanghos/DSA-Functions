#include <bits/stdc++.h>
using namespace std;

bool dp(int index, int sum, int n, vector<int> &nums) {
    if (sum == 0) return true;
    if (index == n - 1) return nums[index] == sum;

    bool ans = dp(index + 1, sum, n, nums);
    if (nums[index] <= sum) {
        ans |= dp(index + 1, sum - nums[index], n, nums);
    }

    return ans;
}

int32_t main() {

    int n, sum = 0; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        sum += nums[i];
    }

    if (sum % 2) return false;
    sum >>= 1;

    cout << dp(0, sum, n, nums);
    return 0;
}