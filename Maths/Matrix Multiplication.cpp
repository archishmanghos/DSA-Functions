void multiplymat(int A[][N], int B[][N], int M)	//Matrix multiplication
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			res[i][j] = 0;
			for (int k = 0; k < M; k++)
				res[i][j] += A[i][k] * B[k][j];
		}
	}
}