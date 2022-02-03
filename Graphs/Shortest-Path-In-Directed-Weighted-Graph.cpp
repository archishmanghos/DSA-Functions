// find the toposort and use the topoSort stack and use the normal minimum weight finding algo

void topSort(int node, stack<int> &st) {
    if (visited[node]) {
        return;
    }

    visited[node] = true;
    for (auto child: adj[node]) {
        topSort(child.first, st);
    }

    st.push(node);
}

void distFromEachNode(int node, stack<int> topoSort) {
    dist[node] = 0;
    while (!topoSort.empty()) {
        int node = topoSort.top();
        topoSort.pop();

        if (dist[node] != INF) {
            for (auto child: adj[node]) {
                dist[child.first] = min(dist[child.first], dist[node] + child.second);
            }
        }
    }
}