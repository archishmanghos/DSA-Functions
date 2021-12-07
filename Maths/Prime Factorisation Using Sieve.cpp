void PFusingSieve(int n)	//Prime Factorization using Sieve
{
	int pf[mxN];
	memset(pf, -1, sizeof(pf));
	for (int i = 2; i <= mxN; i++)
	{
		if (pf[i] == -1)
		{
			for (int j = i; j <= mxN; j += i)
			{
				if (pf[j] == -1)
					pf[j] = i;
			}
		}
	}
}