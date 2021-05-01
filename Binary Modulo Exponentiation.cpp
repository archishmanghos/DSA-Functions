int BinExp(int a, int n)	//Binary/Modulo Exponentiation
{
	int ans = 1;
	while (n > 0)
	{
		if (n & 1)
		{
			ans = ((ans % mod) * (a % mod)) % mod;
			--n;
		}
		else
		{
			a = ((a % mod) * (a % mod)) % mod;
			n /= 2;
		}
	}
	return ans;
}