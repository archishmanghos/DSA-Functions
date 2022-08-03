#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int n, d, totSum = 0, mod = 1e9 + 7; cin >> n >> d;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        totSum += arr[i];
    }

    vector<vector<int>> cache(n, vector<int>(totSum + 1, 0));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = totSum; j >= 0; j--) {
            if (i == n - 1) {
                if (totSum - 2 * j == d) cache[i][j] = 1;
                if (j + arr[i] <= totSum and totSum - 2 * (j + arr[i]) == d) {
                    cache[i][j] = (cache[i][j] + 1) % mod;
                }
            } else {
                cache[i][j] = cache[i + 1][j];
                if (j + arr[i] <= totSum) cache[i][j] = (cache[i][j] + (cache[i + 1][j + arr[i]]) % mod) % mod;
            }
        }
    }

    cout << cache[0][0];
    return 0;
}