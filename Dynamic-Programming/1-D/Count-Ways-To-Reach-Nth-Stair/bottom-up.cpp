#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int N, mod = 1e9 + 7; cin >> N;
    vector<int> cache(N + 1, -1);
    cache[0] = cache[1] = 1;
    for (int i = 2; i <= N; i++) {
        cache[i] = ((cache[i - 1] % mod) + (cache[i - 2] % mod)) % mod;
    }

    cout << cache[N];

    return 0;
}