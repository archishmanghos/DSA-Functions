int N, M, U, V;
vector<int> adj[mxN], colour(mxN);

bool checkCanBeColoured(int node) {
    for (int child: adj[node]) {
        if (colour[child] == -1) {
            colour[child] = 1 - colour[node];
            if(!checkCanBeColoured(child)){
                return false;
            }
        } else {
            if (colour[child] == colour[node]) {
                return false;
            }
        }
    }
    return true;
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

    colour.assign(mxN, -1);
    for (int i = 1; i <= N; i++) {
        if (colour[i] == -1) {
            if (!checkCanBeColoured(i)) {
                cout << "NO" << '\n';
                return 0;
            }
        }
    }

    cout << "YES" << '\n';
    return 0;
}