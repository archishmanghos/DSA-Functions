// check if a node is visited and the node is not the parent of the current Node, it is a cycle

bool findCycle(int node, int parent) {

    visited[node] = true;
    bool ans = false;
    for (int child: adj[node]) {
        ans |= (visited[child] and child != parent);
        if (!visited[child]) {
            ans |= findCycle(child, node);
        }
    }

    return ans;
}