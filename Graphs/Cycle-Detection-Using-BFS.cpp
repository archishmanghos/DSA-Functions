// check if a node is visited and the node is not the parent of the current Node, it is a cycle

int N, M, U, V;
vector<int> adj[mxN], visited(mxN);

bool findCycle(int root) {
    queue<pair<int, int>> q;
    q.push({root, -1});
    bool ans = false;

    while (!q.empty()) {
        pair<int, int> curNode = q.front();
        q.pop();
        visited[curNode.first] = true;
        for (int child: adj[curNode.first]) {
            ans |= (visited[child] and child != curNode.second);
            if (!visited[child]) {
                q.push({child, curNode.first});
            }
        }
    }

    return ans;
}