/*Pick the key with the minimum value from the minimum heap, which is not in the MST
and include the node with the min key in the MST. Now, traverse through the adjacent nodes
of the node found and if the adjacent node is not in the MST, compare the key of the node
and the weight of the edge now. Take the minimum and push the new key in the min heap and mark the
parent of the adjacent node as the current node. Coninue the steps till all the nodes have been included.*/

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
                if (key[child.first] > child.second) {
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