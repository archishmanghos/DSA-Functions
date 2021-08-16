
/*Time Complexity -> Union : O(MlogM), where M is the number of 							edges
				   Finding Parent: O(4α) ~ O(4) ~ O(1)

Space Complexity -> O(N) approximately, considering parent and 					rank array.*/


int parent[mxN], rank[mxN];

void makeSet()
{
	for(int i = 1; i <= N; i++)
	{
		parent[i] = i;
		rank[i] = 0;
	}
}

int findParent(int x)
{
	if(x == parent[x])
		return x;

	return parent[x] = findParent(parent[x]);
}

void unionOfEdges(int u, int v)
{
	int parentU = findParent(u);
	int parentV = findParent(v);

	if(rank[parentU] < rank[parentV])
		parent[parentU] = parentV;
	else if(rank[parentU] > rank[parentV])
		parent[parentV] = parentU;
	else
	{
		parent[parentU] = parentV;
		rank[parentV] += 1;
	}
}