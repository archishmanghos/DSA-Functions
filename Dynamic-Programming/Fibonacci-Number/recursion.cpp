#include <bits/stdc++.h>
using namespace std;

int fib(int N) {
    if (N <= 1) return N;
    return fib(N - 1) + fib(N - 2);
}

int32_t main() {

    int N; cin >> N;
    cout << fib(N);

    return 0;
}