#include <bits/stdc++.h>
using namespace std;

int dp(int index, vector<int> &nums) {
    if (index <= 0) return index == 0 ? nums[index] : 0;

    return max(dp(index - 2, nums) + nums[index], dp(index - 1, nums));
}

int32_t main() {

    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << dp(n - 1, nums);
    return 0;
}