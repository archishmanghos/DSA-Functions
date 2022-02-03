// maintain indegree array, if indegree becomes 0, push into the queue and rest simple bfs

void topSort() {
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (!inDegree[i]) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << ' ';
        for (int child: adj[node]) {
            inDegree[child] -= 1;
            if (!inDegree[child]) {
                q.push(child);
            }
        }
    }
}