#include <bits/stdc++.h>
using namespace std;

int dp(int N, vector<int> &cache, int mod = 1e9 + 7) {
    if (N <= 1) return 1;
    if (cache[N] != -1) return cache[N];

    return cache[N] = ((dp(N - 1, cache) % mod) + (dp(N - 2, cache) % mod)) % mod;
}

int32_t main() {

    int N; cin >> N;
    vector<int> cache(N + 1, -1);
    cout << dp(N, cache);

    return 0;
}