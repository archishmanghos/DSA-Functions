#include <bits/stdc++.h>
using namespace std;

bool dp(int index, int sum, int n, int k, vector<int> &arr, vector<vector<int>> &cache) {
    if (sum == 0) return true;
    if (index == n - 1) return arr[index] == sum;
    if (cache[index][sum] != -1) return cache[index][sum];

    bool ans = dp(index + 1, sum, n, k, arr, cache);
    if (arr[index] <= sum) {
        ans |= dp(index + 1, sum - arr[index], n, k, arr, cache);
    }

    return cache[index][sum] = ans;
}

int32_t main() {

    int n, target; cin >> n >> target;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<vector<int>> cache(n, vector<int>(target + 1, -1));
    cout << dp(0, target, n, k, arr, cache);
    return 0;
}