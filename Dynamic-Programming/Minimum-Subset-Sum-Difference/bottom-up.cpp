#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int n, totSum = 0; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        totSum += nums[i];
    }

    vector<vector<int>> cache(n, vector<int>(totSum + 1, 0));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = totSum; j >= 0; j--) {
            if (i == n - 1) {
                int sumAfterNotPick = j, sumAfterPick = j - arr[i];
                int remSumAfterNotPick = totSum - sumAfterNotPick , remSumAfterPick = totSum - sumAfterPick;
                if (j == totSum) {
                    cache[i][j] = abs(sumAfterPick - remSumAfterPick);
                } else if (j - arr[i] > 0) {
                    cache[i][j] = min(abs(sumAfterPick - remSumAfterPick), abs(sumAfterNotPick - remSumAfterNotPick));
                } else {
                    cache[i][j] = abs(sumAfterNotPick - remSumAfterNotPick);
                }
            } else {
                cache[i][j] = cache[i + 1][j];
                if (j - arr[i] > 0) {
                    cache[i][j] = min(cache[i][j], cache[i + 1][j - arr[i]]);
                }
            }
        }
    }

    cout << cache[0][totSum];
    return 0;
}