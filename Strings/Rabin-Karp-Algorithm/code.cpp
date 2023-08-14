#include <bits/stdc++.h>
using namespace std;

int rabinKarp(string a, string b) { // find b in a
	auto add = [](int a, int b, int mod = 31) {
		long c = a + b;
		if (c >= mod) c -= mod;
		return c;
	};

	auto sub = [](int a, int b, int mod = 31) {
		long c = a - b;
		if (c < 0) c += mod;
		return c;
	};

	auto mul = [](int a, int b, int mod = 31) {
		return (a * 1ll * b) % mod;
	};

	auto getHash = [&](string s, int mod = 1e9 + 7) {
		int hash = 0;
		for (int i = s.size() - 1, j = 1; i >= 0; i--, j = mul(j, 10)) {
			hash = add(hash, mul(((s[i] - 'a') + 1), j));
		}
		return hash;
	};

	int hash = getHash(b);

	auto findPattern = [&](string x, string y, int mod = 1e9 + 7) {
		long rollingHash = 0, i, j, n = y.size();
		for (i = n - 2, j = 1; i >= 0; i--, j = mul(j, 10)) {
			rollingHash = add(rollingHash, mul((x[i] - 'a') + 1, mul(j, 10)));
		}

		for (i = n - 1; i < x.size(); i++) {
			if (i - n >= 0) {
				rollingHash = mul(sub(rollingHash, mul(j, (x[i - n] - 'a') + 1)), 10);
			}

			rollingHash = add(rollingHash, (x[i] - 'a') + 1);
			if (rollingHash == hash) if (x.substr(i - n + 1, n) == y) return true;
		}

		return false;
	};


	return findPattern(a, b);
}

int main() {
	string a, b; cin >> a >> b;
	cout << rabinKarp(a, b);
	return 0;
}