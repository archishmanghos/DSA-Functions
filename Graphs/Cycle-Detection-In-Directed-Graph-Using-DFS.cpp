// Same as undirected graph but use a dfsVisited array to check if dfs call has been over for that cycle

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