//There are 3 steps:
//1) Find the order of last node to finish using kind of toposort
//2) Transpose the graph, i.e, reverse the edges
//3) Now, start with top of stack and find the SCC using DFS

void transposeOfGraph() {
    for (int i = 1; i <= N; i++) {
        for (int child: adj[i]) {
            newAdj[child].push_back(i);
        }
    }
}

void kindOfTopoSort(int node) {
    if (visited[node]) {
        return;
    }

    visited[node] = true;
    for (int child: adj[node]) {
        kindOfTopoSort(child);
    }

    topoSort.push(node);
}

void printSCC(int node) {
    if (visited[node]) {
        return;
    }

    visited[node] = true;
    cout << node << ' ';
    for (int child: newAdj[node]) {
        printSCC(child);
    }
}

void kosaraju() {
    visited.assign(N + 2, false);
    while (!topoSort.empty()) {
        if (!visited[topoSort.top()]) {
            printSCC(topoSort.top());
            cout << '\n';
        }
        topoSort.pop();
    }
}
