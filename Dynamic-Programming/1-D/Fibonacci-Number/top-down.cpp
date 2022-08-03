#include <bits/stdc++.h>
using namespace std;

int fib(int N, vector<int> &cache) {
    if (N <= 1) return N;
    if (cache[N] != -1) return cache[N];

    return cache[N] = fib(N - 1, cache) + fib(N - 2, cache);
}

int32_t main() {

    int N; cin >> N;
    vector<int> cache(N + 1, -1);
    cout << fib(N, cache);

    return 0;
}