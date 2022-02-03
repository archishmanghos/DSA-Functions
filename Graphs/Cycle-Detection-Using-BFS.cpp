int N, M, U, V;
vector<int> adj[mxN], visited(mxN);

bool findCycle(int root) {
    queue<pair<int, int>> q;
    q.push({root, -1});
    bool ans = false;

    while (!q.empty()) {
        pair<int, int> curNode = q.front();
        q.pop();
        visited[curNode.first] = true;
        for (int child: adj[curNode.first]) {
            ans |= (visited[child] and child != curNode.second);
            if (!visited[child]) {
                q.push({child, curNode.first});
            }
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
            if (findCycle(i)) {
                cout << "YES" << ' ';
            } else {
                cout << "NO" << ' ';
            }
        }
    }
    return 0;
}