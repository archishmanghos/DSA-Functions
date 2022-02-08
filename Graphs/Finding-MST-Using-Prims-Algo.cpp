void findMST() {
    parent.assign(N + 2, -1);
    key.assign(N + 2, INF);
    mst.assign(N + 2, false);
    key[0] = 0;
    priority_queue < pair < int, int >, vector < pair < int, int >>, greater < pair < int, int>>> minHeap;
    minHeap.push({key[0], 0});

    for (int it = 1; it < N; it++) {
        int node = minHeap.top().second;
        minHeap.pop();
        mst[node] = true;

        for (auto child: adj[node]) {
            if (!mst[child.first]) {
                if (key[child.first] > child.second and !mst[child.first]) {
                    key[child.first] = child.second;
                    parent[child.first] = node;
                    minHeap.push({key[child.first], child.first});
                }
            }
        }
    }

    for (int i = 1; i < N; i++) {
        tree[parent[i]].push_back(i);
        tree[i].push_back(parent[i]);
    }
}