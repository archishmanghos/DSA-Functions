class SegTree {
private:
	int n;
	vector<int64_t> A;

	void build(int index, int l, int r, vector<int> &v) {
		if (l == r) {
			if (l <= v.size()) {
				A[index] = v[l];
			}
			return;
		}

		int mid = l + (r - l) / 2;
		build(2 * index, l, mid, v);
		build(2 * index + 1, mid + 1, r, v);
		A[index] = A[2 * index] + A[2 * index + 1]; // change with the problem's function
	}

	int query(int index, int l, int r, int lx, int rx) {
		if (l >= lx and r <= rx) return A[index];
		if (r < lx or l > rx) return 0;
		int mid = l + (r - l) / 2;
		return query(2 * index, l, mid, lx, rx) + query(2 * index + 1, mid + 1, r, lx, rx);
	}

	void update(int index, int l, int r, int idx, int val) {
		if (l == r) {
			A[index] = val;
			return;
		}

		int mid = l + (r - l) / 2;
		if (idx <= mid) update(2 * index, l, mid, idx, val);
		else update(2 * index + 1, mid + 1, r, idx, val);
		A[index] = A[2 * index] + A[2 * index + 1]; // change with the problem's function
	}

public:
	void init(int n1) {
		n = 1;
		while (n < n1) n <<= 1;
		A.assign(2 * n, 0);
	}

	void build(vector<int> &A) {
		build(1, 1, n, A);
	}

	int64_t query(int l, int r) {
		return query(1, 1, n, l, r);
	}

	void update(int idx, int val) {
		update(1, 1, n, idx, val);
	}

	void print() {
		for (int i = 1; i < 2 * n; i++) {
			cout << i << ": " << A[i] << '\n';
		}
	}
};

// All arrays are 1 based indexed and should alse be same in main function.
// Init should be called as soon as this class is called.
// Remember to build the tree before operations.
// Use print function in case of any discrepancy.