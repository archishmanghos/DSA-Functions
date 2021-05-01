bool prime(int n)	//primality test
{
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return true;
	}
	return false;
}