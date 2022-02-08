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