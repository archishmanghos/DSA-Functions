# Z Algorithm

[Tutorial Blog](https://cp-algorithms.com/string/z-function.html)
<br>
Code ->

```c++
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
```

<br>

<h2>Practice Problems </h2>

<br>

[Find the Index of the First Occurrence in a String - Leetcode](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/)

<br>

<details><summary> Solution </summary >

```c++
class Solution {
public:
	int strStr(string haystack, string needle) {
		string s = needle + '$' + haystack;
		int n = s.size(), l = 0, r = 0;
		vector<int> z(n, 0);

		for (int i = 1; i < n; i++) {
			if (i <= r) z[i] = min(z[i - l], r - i + 1);
			while (i + z[i] < n and s[i + z[i]] == s[z[i]]) z[i]++;
			if (i > needle.size() and z[i] == (int)needle.size()) return (i - (int)needle.size() - 1);
			if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
		}

		return -1;
	}
};
```

</details >