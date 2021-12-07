vector<int> inDegree(N + 5, 0);
queue<int> q;
for(int i = 1; i <= N; i++)
{
	for(int j : adj[i])
		inDegree[j] += 1;
}

for(int i = 1; i <= N; i++)
{
	if(inDegree[i] == 0)
		q.push(i);
}

memset(visited, false, sizeof(visited));
vector<int> ans;
while(!q.empty())
{
	int node = q.front();
	q.pop();

	if(visited[node])
		continue;

	visited[node] = true;
	for(int i : adj[node])
	{
		inDegree[i] -= 1;
		if(inDegree[i] == 0)
			q.push(i);
	}

	ans.push_back(node);
}
	
if(ans.size() != N)
{
	cout << -1;
	return 0;
}

for(int i : ans)
	cout << i << ' ';