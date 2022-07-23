#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int n; cin >> n;
    vector<int> nums(n), cache(n, 0);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cache[0] = nums[0];

    for (int i = 1; i < n; i++) {
        cache[i] = max((i > 1 ? cache[i - 2] : 0) + nums[i], cache[i - 1]);
    }

    cout << cache[n - 1];
    return 0;
}