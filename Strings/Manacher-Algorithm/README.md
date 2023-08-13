# Manacher's Algorithm

[Detailed Blog](https://cp-algorithms.com/string/manacher.html)
<br>
Code ->

```c++
void manacher(string s) {
	// convert s to odd size to apply algo
	string s1 = string(1, '$');
	for (int i = 0; i < s.size(); i++) s1 += string(1, '#') + s[i];
	s1 += "#^";

	int n = s1.size();
	int p[n] = {0}, l = 1, r = 1;
	for (int i = 1; i < n; i++) {
		// case 1: i > r -> p[i] = 0
		// case 2: i <= r but mirror point's pal extends out of outer pal -> r - i and then trivial
		// case 3: i <= r and mirror point's pal stays inside of outer pal -> p1[l + r - i] where l + r - i is the mirror of i

		p[i] = max(0, min(p[l + r - i], r - i));

		// trivial algo ->
		while (s1[i - p[i]] == s1[i + p[i]]) p[i]++;

		// extending boundaries of longest pal
		if (i + p[i] > r) l = i - p[i], r = i + p[i];
	}

	for (int i = 2; i < n; i += 2) cout << (p[i] >> 1) << ' ';
}
```

<br>

<h2>Practice Problems </h2>

<br>

[Longest Palindromic Substring - Leetcode](https://leetcode.com/problems/longest-palindromic-substring/)

<br>

<details><summary>Solution</summary >

```c++
class Solution {
public:
	string longestPalindrome(string s) {
		string s1 = string(1, '$');
		for (int i = 0; i < s.size(); i++) s1 += string(1, '#') + s[i];
		s1 += "#^";
		int n = s1.size(), p[n + 2], l = 1, r = 1;
		memset(p, 0, sizeof(p));
		for (int i = 1; i < n; i++) {
			p[i] = max (0, min(p[l + r - i], r - i));
			while (s1[i - p[i]] == s1[i + p[i]]) p[i]++;
			if (i + p[i] > r) l = i - p[i], r = i + p[i];
		}

		int maxLen = *max_element (p + 1, p + n + 1);
		for (int i = 1; i < n; i++) {
			if (p[i] == maxLen) {
				string answer = "";
				if (s1[i] != '#') answer += s1[i];
				int k = p[i] - 2, j = i - (s1[i] == '#' ? 1 : 2);
				while (k > 0) {
					answer = s1[j] + answer + s1[j];
					j -= 2;
					k -= 2;
				}

				return answer;
			}
		}

		return "-1";
	}
};
```

</details>