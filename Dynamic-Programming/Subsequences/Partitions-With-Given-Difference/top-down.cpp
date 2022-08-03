#include <bits/stdc++.h>
using namespace std;

int dp(int index, int sum, int d, int n, int totSum, vector<int> &arr, vector<vector<int>> &cache, int mod = 1e9 + 7) {
    if (index == n - 1) {
        int take = sum + arr[n - 1], notTake = sum;
        int diff1 = totSum - 2 * take, diff2 = totSum - 2 * notTake;
        if (diff1 == d and diff2 == d) return 2;
        if (diff1 == d or diff2 == d) return 1;
        return 0;
    }
    if (cache[index][sum] != -1) return cache[index][sum];

    int take = dp(index + 1, sum + arr[index], d, n, totSum, arr, cache) % mod, notTake = dp(index + 1, sum, d, n, totSum, arr, cache) % mod;
    return cache[index][sum] = (take + notTake) % mod;
}

int32_t main() {

    int n, d, totSum = 0; cin >> n >> d;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        totSum += arr[i];
    }

    vector<vector<int>> cache(n, vector<int>(totSum + 1, -1));
    cout << dp(0, 0, d, n, totSum, arr, cache);
    return 0;
}