//Relax edges exactly N-1 times
//If edges relax the N-th time, graph contains a negative cycle
//Else, print the distances

void bellmanFord(int sourceNode) {
    dist.assign(N + 2, INF);
    dist[sourceNode] = 0;

    for (int i = 1; i <= N - 1; i++) {
        for (auto edge: edges) {
            int node1 = edge.first.first;
            int node2 = edge.first.second;
            int weight = edge.second;
            dist[node2] = min(dist[node1] + weight, dist[node2]);
        }
    }

    for (auto edge: edges) {
        int node1 = edge.first.first;
        int node2 = edge.first.second;
        int weight = edge.second;
        if (dist[node1] + weight < dist[node2]) {
            cout << "Negative Cycle Found";
            return;
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << dist[i] << ' ';
    }
}