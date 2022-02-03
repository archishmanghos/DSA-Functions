int N, M, U, V;
vector<int> adj[mxN], visited(mxN);

bool findCycle(int node, int parent) {

    visited[node] = true;
    bool ans = false;
    for (int child: adj[node]) {
        ans |= (visited[child] and child != parent);
        if (!visited[child]) {
            ans |= findCycle(child, node);
        }
    }

    return ans;
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
        adj[V].push_back(U);
    }

    visited.assign(mxN, false);
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            if (findCycle(i, -1)) {
                cout << "YES" << ' ';
            } else {
                cout << "NO" << ' ';
            }
        }
    }
    return 0;
}