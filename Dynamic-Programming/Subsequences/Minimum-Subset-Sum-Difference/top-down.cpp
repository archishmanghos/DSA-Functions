#include <bits/stdc++.h>
using namespace std;

int dp(int index, int sum, int totSum, int n, vector<int> &arr, vector<vector<int>> &cache) {
    if (index == n - 1) {
        int sumAfterNotPick = sum, sumAfterPick = sum - arr[index];
        int remSumAfterNotPick = totSum - sumAfterNotPick , remsumAfterPick = totSum - sumAfterPick;
        if (sum == totSum) {
            return abs(sumAfterPick - remsumAfterPick);
        }
        if (sum - arr[index] > 0) {
            return min(abs(sumAfterPick - remsumAfterPick), abs(sumAfterNotPick - remSumAfterNotPick));
        }

        return abs(sumAfterNotPick - remSumAfterNotPick);
    }

    if (cache[index][sum] != -1) return cache[index][sum];

    int ans = dp(index + 1, sum, totSum, n, arr, cache);
    if (sum - arr[index] > 0) {
        ans = min(ans, dp(index + 1, sum - arr[index], totSum, n, arr, cache));
    }

    return cache[index][sum] = ans;
}

int32_t main() {

    int n, totSum = 0; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        totSum += nums[i];
    }

    vector<vector<int>> cache(n, vector<int>(totSum + 1, -1));
    cout << dp(0, totSum, totSum, n, arr, cache);
    return 0;
}