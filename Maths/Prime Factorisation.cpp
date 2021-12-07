void PF(int n)	//Prime Factorization
{
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			int cnt = 0;
			while (n % i == 0)
			{
				++cnt;
				n /= i;
			}
			cout << i << " ^ " << cnt << '\n';
		}
	}
	if (n > 1)
		cout << n << " ^ " << 1 << '\n';
}