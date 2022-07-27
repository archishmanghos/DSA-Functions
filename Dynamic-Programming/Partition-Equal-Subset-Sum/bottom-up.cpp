#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int n, sum = 0; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        sum += nums[i];
    }

    if (sum % 2) return false;
    vector<vector<bool>> cache(n, vector<bool>(sum + 1, 0));
    sum >>= 1;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= sum; j++) {
            if (i == n - 1) cache[i][j] = (j == nums[i]);
            else {
                if (j == 0) cache[i][j] = 1;
                else {
                    cache[i][j] = cache[i + 1][j];
                    if (nums[i] <= j) {
                        cache[i][j] = cache[i][j] or cache[i + 1][j - nums[i]];
                    }
                }
            }
        }
    }

    cout << cache[0][sum];
    return 0;
}