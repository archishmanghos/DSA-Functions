#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int N; cin >> N;
    vector<int> cache(N + 1, -1);
    cache[0] = 0, cache[1] = 1;

    for (int i = 2; i <= N; i++) {
        cache[i] = cache[i - 1] + cache[i - 2];
    }

    cout << cache[N];

    return 0;
}