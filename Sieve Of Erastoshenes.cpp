void SieveOfEratosthenes()	//Sieve Of Eratosthenes
{
	bool isPrime[mxN];
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i <= mxN; i++)
	{
		if (isPrime[i])
		{
			for (int j = i * i; j <= mxN; j += i)
				isPrime[j] = false;
		}
	}
}