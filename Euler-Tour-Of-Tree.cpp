int N, U, V, visited[mxN];
vector<int> adj[mxN];

void dfs(int node)
{
	cout << node << ' ';
	visited[node] = 1;

	for(auto it : adj[node])
	{
		if(!visited[it])
		{
			dfs(it);
			cout << node << ' ';
		}
	}
	
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("error.txt", "w", stderr);
	#endif

	cin >> N;
	for(int i = 1; i <= N - 1; i++)
	{
		cin >> U >> V;
		adj[U].push_back(V);
		adj[V].push_back(U);
	}

	for(int i = 1; i <= N; i++)
		if(adj[i].size())
			sort(adj[i].begin(), adj[i].end());

	memset(visited, 0, sizeof(visited));
	dfs(1);

    return 0;
}