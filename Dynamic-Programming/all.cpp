#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include <G:\DSA-Contests\archidebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = LLONG_MAX;

int dp(int start, int end, vector<int> &nums) {
    vector<int> cache(end + 2, 0);
    for (int i = end - 1; i >= start; i--) {
        cache[i] = max(cache[i + 2] + nums[i], cache[i + 1]);
    }

    return cache[start];
}

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    return max(dp(0, n - 1, nums), dp(1, n, nums));
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif

    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    if (n == 1) return nums[0];
    cout << max(dp(0, n - 1, nums), dp(1, n, nums));

    return 0;
}