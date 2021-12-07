
/*

Check if the table to be built is immutable.
Range update queries mean whole sparse table to be rebuilt.

Time complexity: -> Building the sparse table: O(NlogN)
		 -> Processing Queries 		: O(logN), if the function is not idempotent
						  O(1), if the function is idempotent, F(A, A) = A

Common idempotent fns: min, max, gcd, bitwise or, bitwise and

Space complexity: O(NlogN)

*/

/*if function is idempotent, uncomment this =>

int logg[mxN + 1];
logg[1] = 0;
for (int i = 2; i <= mxN; i++)
    logg[i] = logg[i/2] + 1;*/


int sparse[mxN][K + 1];

for(int i = 0; i < N; i++)
    sparse[i][0] = A[i];

for (int j = 1; j <= K; j++)
    for (int i = 0; i + (1 << j) <= N; i++)
        sparse[i][j] = sparse[i][j-1] + sparse[i + (1 << (j - 1))][j - 1];

// => Queries part

/*if function is not idempotent uncomment this and remember to change the function according to the problem =>

int ans = 0;
for (int j = K; j >= 0; j--) 
{
    if ((1 << j) <= R - L + 1) 
    {
        ans += sparse[L][j];
        L += (1 << j);
    }
}
*/
/*if function is idempotent, uncomment this and remember to change the function according to the problem =>

int j = logg[R - L + 1];
int ans = min(sparse[L][j], sparse[R - (1 << j) + 1][j]);*/
