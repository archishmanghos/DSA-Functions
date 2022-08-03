#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int n, target; cin >> n >> target;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<vector<bool>> cache(n, vector<bool>(target + 1, false));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = target; j >= 0; j--) {
            if (i == n - 1) cache[i][j] = (j == arr[i]);
            else {
                if (j == 0) cache[i][j] = true;
                else {
                    cache[i][j] = cache[i + 1][j];
                    if (arr[i] <= j) {
                        cache[i][j] = cache[i][j] or cache[i + 1][j - arr[i]];
                    }
                }
            }
        }
    }

    cout << cache[0][target];
    return 0;
}