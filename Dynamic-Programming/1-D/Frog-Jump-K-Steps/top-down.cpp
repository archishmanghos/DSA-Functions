#include <bits/stdc++.h>
using namespace std;

int dp(int index, int N, int K, vector<int> &H, vector<int> &cache) {
    if (index == 0) return 0;
    if (cache[index] != -1) return cache[index];

    int ans = INT_MAX;
    for (int i = index - 1; i >= index - K and i >= 0; i--) {
        ans = min(ans, dp(i, N, K, H, cache) + abs(H[i] - H[index]));
    }

    return cache[index] = ans;
}

int32_t main() {

    int N, K; cin >> N >> K;
    vector<int> H(N), cache(N, -1);
    for (int i = 0; i < N; i++) cin >> H[i];

    cout << dp(N - 1, N, K, H, cache);

    return 0;
}