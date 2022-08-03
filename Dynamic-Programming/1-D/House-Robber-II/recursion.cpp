#include <bits/stdc++.h>
using namespace std;

int dp(int index, int n, vector<int> &nums) {
    if (index >= n) return 0;

    int robThisHouse = dp(index + 2, n, nums) + nums[index];
    int dontRobThisHouse = dp(index + 1, n, nums);
    return max(robThisHouse, dontRobThisHouse);
}

int32_t main() {

    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    if (n == 1) return nums[0];
    cout << max(dp(0, n - 1, nums), dp(1, n, nums));

    return 0;
}