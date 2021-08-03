const int sieveLimit = 1e6 + 5;

bool isPrime[sieveLimit];

void SieveOfEratosthenes()	//Sieve Of Eratosthenes
{
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i <= sieveLimit; i++)
	{
		if (isPrime[i])
		{
			for (int j = i * i; j <= sieveLimit; j += i)
				isPrime[j] = false;
		}
	}
}