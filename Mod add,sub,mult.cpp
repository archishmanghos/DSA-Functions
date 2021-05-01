int add(int a, int b, int p = mod)
{
	int c = a + b;
	if (c >= p)
		c -= p;
	return c;
}

int sub(int a, int b, int p = mod)
{
	int c = a - b;
	if (c < 0)
		c += p;
	return c;
}

int mul(int a, int b, int p = mod)
{
	return (a * (int)1 * b) % p;
}