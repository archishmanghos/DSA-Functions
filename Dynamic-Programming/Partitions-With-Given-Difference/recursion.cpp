#include <bits/stdc++.h>
using namespace std;

int dp(int index, int sum, int d, int n, int totSum, vector<int> &arr, int mod = 1e9 + 7) {
    if (index == n - 1) {
        int take = sum + arr[n - 1], notTake = sum;
        int diff1 = totSum - 2 * take, diff2 = totSum - 2 * notTake;
        if (diff1 == d and diff2 == d) return 2;
        if (diff1 == d or diff2 == d) return 1;
        return 0;
    }

    int take = dp(index + 1, sum + arr[index], d, n, totSum, arr) % mod, notTake = dp(index + 1, sum, d, n, totSum, arr) % mod;
    return (take + notTake) % mod;
}

int32_t main() {

    int n, d, totSum = 0; cin >> n >> d;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        totSum += arr[i];
    }

    cout << dp(0, 0, d, n, totSum, arr);
    return 0;
}