// Counter logic for Kahn's algo, if graph has cycles, Topo sort can't be generated, hence we count the number of nodes in the topo sort and check if count is equal to number of nodes. Not a recommended algo though, use one with DFS

bool checkCycle() {
    queue<int> q;

    for (int i = 1; i <= N; i++) {
        if (!inDegree[i]) {
            q.push(i);
        }
    }

    int nodesSorted = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        nodesSorted += 1;
        for (int child: adj[node]) {
            inDegree[child] -= 1;
            if (!inDegree[child]) {
                q.push(child);
            }
        }
    }

    return nodesSorted != N;
}