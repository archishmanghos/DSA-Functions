// use normal bfs and colour the nodes alternatively. If any child has same colour as parent, graph can't be bipartite

bool checkCanBeColoured(int node) {
    queue<int> q;
    q.push(node);
    colour[node] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int child: adj[node]) {
            if (colour[child] == -1) {
                colour[child] = 1 - colour[node];
                q.push(child);
            } else {
                if (colour[child] == colour[node]) {
                    return false;
                }
            }
        }
    }

    return true;
}