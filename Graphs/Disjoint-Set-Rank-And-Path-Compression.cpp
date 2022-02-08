/*If we need to do union of 2 nodes, we find out their parents using path compression.
Now, we see if their ranks are same, we attach anyone to another one and increase rank of final parent by 1.
If not same, the lower ranked parent gets attached to the higher ranked parent.*/


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