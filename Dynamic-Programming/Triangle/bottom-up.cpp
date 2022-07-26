#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int n; cin >> n;
    vector<vector<int>> triangle(n);
    for (int i = 0; i < n; i++) {
        vector<int> temp(i + 1);
        for (int j = 0; j <= i; j++) {
            cin >> temp[j];
        }
        triangle[i] = temp;
    }

    vector<vector<int>> cache(n, vector<int> (n, 0));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            if (i == n - 1) cache[i][j] = triangle[i][j];
            else {
                cache[i][j] = cache[i + 1][j] + triangle[i][j];
                if (j < n - 1) cache[i][j] = min(cache[i][j], cache[i + 1][j + 1] + triangle[i][j]);
            }
        }
    }

    cout << cache[0][0];
    return 0;
}