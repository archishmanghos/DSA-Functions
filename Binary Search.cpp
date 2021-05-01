int BS(int l, int r, int x)	//binary-search
{
	while (l <= r)
	{
		int mid = l + (r - l) / 2;
		if (a[mid] == x)
			return mid;
		else if (a[mid] < x)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return -1;
}

double BSwithprecision(int x)	//binary-search with precision
{
	int l = 0, r = x;
	double eps = 1e-9;
	while (r - l > eps)
	{
		int mid = l + (r - l) / 2;
		if (mid * mid < x)
			l = mid;
		else if (mid * mid > x)
			r = mid;
	}
	return l + (r - l) / 2;
}