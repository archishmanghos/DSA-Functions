# Rabin-Karp Algorithm

[Tutorial Video](https://www.youtube.com/watch?v=qQ8vS2btsxI)
<br>
Code ->

```c++
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
```

<br>

<h2>Practice Problems </h2>

<br>

[Repeated String Match - Leetcode](https://leetcode.com/problems/repeated-string-match/description/)

<br>

<details><summary> Solution </summary >

```c++
class Solution {
public:
	int repeatedStringMatch(string a, string b) {
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

		int n1 = a.size(), n2 = b.size(), repeat = 1;
		string x = a;
		while (x.size() < b.size()) {
			x += a;
			repeat++;
		}
		if (x == b) return repeat;
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

		if (findPattern(x, b)) return repeat;
		if (findPattern(x + a, b)) return repeat + 1;
		return -1;
	}
};
```

</details >