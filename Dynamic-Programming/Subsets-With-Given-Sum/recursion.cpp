#include <bits/stdc++.h>
using namespace std;

int dp(int index, int sum, int n, vector<int> &num) {
    if (sum == 0) return 1;
    if (index == n - 1) return num[n - 1] == sum;

    int ans = dp(index + 1, sum, n, num);
    if (num[index] <= sum) {
        ans += dp(index + 1, sum - num[index], n, num);
    }

    return ans;
}

int32_t main() {

    int n, k; cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << dp(0, k, n, nums);
    return 0;
}