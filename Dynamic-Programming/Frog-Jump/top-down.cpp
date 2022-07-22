#include <bits/stdc++.h>
using namespace std;

int dp(int index, int N, vector<int> &heights, vector<int> &cache) {
    if (index == N - 1) return 0;
    if (cache[index] != -1) return cache[index];
    int ans = dp(index + 1, N, heights, cache) + abs(heights[index + 1] - heights[index]);
    if (index + 2 < N) ans = min(ans, dp(index + 2, N, heights, cache) + abs(heights[index + 2] - heights[index]));
    return cache[index] = ans;
}

int32_t main() {

    int N; cin >> N;
    vector<int> cache(N, -1), heights(N);
    for (int i = 0; i < N; i++) cin >> heights[i];
    cout << dp(0, N, heights, cache);

    return 0;
}