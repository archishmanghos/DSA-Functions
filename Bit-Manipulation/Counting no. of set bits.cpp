void setbits(int n)	//Counting no. of set bits
{
	int ans = 0;
	while (n)
	{
		++ans;
		n &= (n - 1);
	}
}