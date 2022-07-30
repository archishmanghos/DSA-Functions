#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int n, amount; cin >> n >> amount;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    vector<vector<int>> cache(n, vector<int>(amount + 1, 0));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= amount; j++) {
            if (j == 0) cache[i][j] = 1;
            else if (i == n - 1) cache[i][j] = (j % coins[i] == 0);
            else {
                cache[i][j] = cache[i + 1][j];
                if (coins[i] <= j) cache[i][j] += cache[i][j - coins[i]];
            }
        }
    }

    cout << cache[0][amount];
    return 0;
}