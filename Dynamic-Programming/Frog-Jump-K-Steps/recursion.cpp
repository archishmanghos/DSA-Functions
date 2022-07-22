#include <bits/stdc++.h>
using namespace std;

int dp(int index, int N, int K, vector<int> &H) {
    if (index == 0) return 0;

    int ans = INT_MAX;
    for (int i = index - 1; i >= index - K and i >= 0; i--) {
        ans = min(ans, dp(i, N, K, H) + abs(H[i] - H[index]));
    }

    return ans;
}

int32_t main() {

    int N, K; cin >> N >> K;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];

    cout << dp(N - 1, N, K, H);

    return 0;
}