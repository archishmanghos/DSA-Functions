#include <bits/stdc++.h>
using namespace std;

int dp(int N, int mod = 1e9 + 7) {
    if (N <= 1) return 1;

    return ((dp(N - 1) % mod) + (dp(N - 2) % mod)) % mod;
}

int32_t main() {

    int N; cin >> N;
    cout << dp(N);

    return 0;
}