// Use a stack and perform normal dfs, when dfs is over for a node, push the node into the stack

void topSort(int node, stack<int> &st) {
    if (visited[node]) {
        return;
    }

    visited[node] = true;
    for (int child: adj[node]) {
        topSort(child, st);
    }

    st.push(node);
}