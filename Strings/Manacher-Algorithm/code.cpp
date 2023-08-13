#include <bits/stdc++.h>
using namespace std;

void manacher(string s) {
	string s1 = string(1, '$');
	for (int i = 0; i < s.size(); i++) s1 += string(1, '#') + s[i];
	s1 += "#^";

	int n = s1.size();
	int p[n] = {0}, l = 1, r = 1;
	for (int i = 1; i < n; i++) {
		p[i] = max(0, min(p[l + r - i], r - i));
		while (s1[i - p[i]] == s1[i + p[i]]) p[i]++;
		if (i + p[i] > r) l = i - p[i], r = i + p[i];
	}

	for (int i = 2; i < n; i += 2) cout << (p[i] >> 1) << ' ';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	string S; cin >> S;
	manacher(S);
	return 0;
}