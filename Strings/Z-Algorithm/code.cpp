#include <bits/stdc++.h>
using namespace std;

void z_algorithm(string s) {
	int n = s.size(), l = 0, r = 0;
	vector<int> z(n, 0);

	for (int i = 1; i < n; i++) {
		if (i <= r) z[i] = min(z[i - l], r - i + 1);
		while (i + z[i] < n and s[i + z[i]] == s[z[i]]) z[i]++;
		if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
	}

	for (int i = 0; i < n; i++) cout << z[i] << ' ';
}

int main() {
	string s; cin >> s;
	z_algorithm(s);
}