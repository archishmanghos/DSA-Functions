bool CPo2(int n)	//Check if n is power of 2
{
	if ((n <= 0) || (n & (n - 1)))
		return false;
	return true;
}