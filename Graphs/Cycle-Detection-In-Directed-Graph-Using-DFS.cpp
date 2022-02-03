// Same as undirected graph but use a dfsVisited array to check if dfs call has been over for that cycle

int N, M, U, V;
vector<int> adj[mxN];
vector<bool> visited(mxN), dfsVisited(mxN);

bool checkCycle(int node) {
    visited[node] = dfsVisited[node] = true;

    for (int child: adj[node]) {
        if (visited[child] and dfsVisited[child]) {
            return true;
        }
        if (!visited[child]) {
            if (checkCycle(child)) {
                return true;
            }
        }
    }

    dfsVisited[node] = false;
    return false;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif


    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> U >> V;
        adj[U].push_back(V);
    }

    visited.assign(N + 2, false);
    dfsVisited.assign(N + 2, false);

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            if (checkCycle(i)) {
                cout << "YES" << '\n';
                return 0;
            }
        }
    }

    cout << "NO" << '\n';
    return 0;
}