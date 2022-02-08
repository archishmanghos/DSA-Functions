/*
Sort the edges according to non-decreasing order of weights.
Pick an edge, see if they belong to same component using disjoint set, if not,
include it in the MST and perform union of the edges.*/

void assignParentAndRank() {
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    rankNode.assign(N + 2, 0);
}

int findParent(int node) {
    if (parent[node] == node) {
        return node;
    }

    return parent[node] = findParent(parent[node]);
}

void unionOfNode(int nodeA, int nodeB) {
    int parentA = findParent(nodeA);
    int parentB = findParent(nodeB);

    if (parentA == parentB) {
        return;
    }

    if (rankNode[parentA] == rankNode[parentB]) {
        parent[parentB] = parentA;
        rankNode[parentA] += 1;
    } else if (rankNode[parentA] > rankNode[parentB]) {
        parent[parentB] = parentA;
    } else {
        parent[parentA] = parentB;
    }
}

void Kruskal() {
    assignParentAndRank();

    int minMSTCost = 0;
    sort(edges.begin(), edges.end());
    for (auto edge: edges) {
        if (findParent(edge.second.first) != findParent(edge.second.second)) {
            unionOfNode(edge.second.first, edge.second.second);
            minMSTCost += edge.first;
            ans.push_back({edge.first, {edge.second.first, edge.second.second}});
        }
    }
}
