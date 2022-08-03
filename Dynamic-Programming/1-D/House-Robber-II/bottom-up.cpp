#include <bits/stdc++.h>
using namespace std;

int dp(int start, int end, vector<int> &nums) {
    vector<int> cache(end + 2, 0);
    for (int i = end - 1; i >= start; i--) {
        cache[i] = max(cache[i + 2] + nums[i], cache[i + 1]);
    }

    return cache[start];
}

int32_t main() {

    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    if (n == 1) return nums[0];
    cout << max(dp(0, n - 1, nums), dp(1, n, nums));

    return 0;
}