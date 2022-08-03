#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int N; cin >> N;
    vector<int> heights(N);
    for (int i = 0; i < N; i++) cin >> heights[i];
    vector<int> cache(N, 0);
    for (int i = N - 2; i >= 0; i--) {
        if (i < N - 2) cache[i] = min(cache[i + 1] + abs(heights[i + 1] - heights[i]), cache[i + 2] + abs(heights[i + 2] - heights[i]));
        else cache[i] = cache[i + 1] + abs(heights[i + 1] - heights[i]);
    }
    cout << cache[0];

    return 0;
}