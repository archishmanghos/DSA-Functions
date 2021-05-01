void MatExp(int N, int M)	//Matrix Exponentiation
{
	int I[N][N];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			I[i][j] = (i == j ? 1 : 0);
	while (M > 0)
	{
		if (M & 1)
		{
			multiplymat(I, arr, M);
			--M;
		}
		else
		{
			multiplymat(arr, arr, M);
			M /= 2;
		}
	}
}