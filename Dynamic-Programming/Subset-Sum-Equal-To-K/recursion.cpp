#include <bits/stdc++.h>
using namespace std;

bool dp(int index, int sum, int n, int k, vector<int> &arr) {
    if (sum == 0) return true;
    if (index == n - 1) return arr[index] == sum;

    bool ans = dp(index + 1, sum, n, k, arr);
    if (arr[index] <= sum) {
        ans |= dp(index + 1, sum - arr[index], n, k, arr);
    }
    return ans;
}

int32_t main() {

    int n, target; cin >> n >> target;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << dp(0, target, n, target, arr);
    return 0;
}