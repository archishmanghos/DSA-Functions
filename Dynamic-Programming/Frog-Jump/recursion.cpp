#include <bits/stdc++.h>
using namespace std;

int dp(int index, int N, vector<int> &heights) {
    if (index == N - 1) return 0;
    int ans = dp(index + 1, N, heights) + abs(heights[index + 1] - heights[index]);
    if (index + 2 < N) ans = min(ans, dp(index + 2, N, heights) + abs(heights[index + 2] - heights[index]));
    return ans;
}

int32_t main() {

    int N; cin >> N;
    vector<int> heights(N);
    for (int i = 0; i < N; i++) cin >> heights[i];
    cout << dp(0, N, heights);

    return 0;
}