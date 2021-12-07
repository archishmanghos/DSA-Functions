
/*Time Complexity -> Union : O(MlogM), where M is the number of 							edges
				   Finding Parent: O(4α) ~ O(4) ~ O(1)

Space Complexity -> O(N) approximately, considering parent and 					rank array.*/


int parent[mxN], rank[mxN];

struct node
{
	int u, v, wt;
};

bool myComp(const node &a, const node &b)
{
	return a.wt < b.wt;
}

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

void Kruskal()
{
	int M, U, V, W; // W is the weight
	makeSet();
	vector<node> newEdges;
	for(int i = 1; i <= M; i++)
	{
		cin >> U >> V >> W;
		node n;
		n.u = U, n.v = V, n.wt = W;
		newEdges.push_back(n);
	}

	sort(newEdges.begin(), newEdges.end(), myComp);
	vector<pair<int, int>> ans;
	int minCost = 0;

	for(node n : newEdges)
	{
		if(findParent(n.u) != findParent(n.v))
		{
			ans.push_back({n.u, n.v});
			minCost += n.wt;
			unionOfEdges(n.u, n.v);
		}
	}
}
