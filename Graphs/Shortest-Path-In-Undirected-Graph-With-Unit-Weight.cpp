// normal bfs, if distance of (node + 1) is less than child, we update the distance of child and push the child into queue

void distFromEachNode(int node) {
    queue<int> q;
    q.push(node);
    dist[node] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int child: adj[node]) {
            if (dist[node] + 1 < dist[child]) {
                dist[child] = dist[node] + 1;
                q.push(child);
            }
        }
    }
}