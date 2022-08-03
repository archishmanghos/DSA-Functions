#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int n; cin >> n;
    vector<vector<int>> points(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> points[i][j];
        }
    }

    vector<vector<int>> cache(n + 1, vector<int>(3, 0));
    for (int i = n - 1; i >= 0; i--) {
        for (int lastTask = 0; lastTask < 3; lastTask++) {
            for (int curTask = 0; curTask < 3; curTask++) {
                if (i > 0) {
                    if (lastTask != curTask) {
                        cache[i][lastTask] = max(cache[i][lastTask], cache[i + 1][curTask] + points[i][lastTask]);
                    }
                } else {
                    cache[i][lastTask] = max(cache[i][lastTask], cache[i + 1][curTask] + points[i][lastTask]);
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 3; i++) {
        ans = max(ans, cache[0][i]);
    }

    cout << ans;
    return 0;
}