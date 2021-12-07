stack<int> st;
bool visited[mxN];

void dfs(int node)
{
	if(visited[node])
		return;
 
	visited[node] = true;
	for(auto it : adj[node])
		dfs(it);
	st.push(node);
}

// for main()

memset(visited, false, sizeof(visited));
for(int i = 1; i <= N; i++)
{
	if(!visited[i])
		dfs(i);
}

vector<int> ans;
while(!st.empty())
{
	ans.push_back(st.top());
	st.pop();
}

for(int i : ans)
	cout << i << ' ';