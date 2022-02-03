// use normal dfs and colour the nodes alternatively. If any child has same colour as parent, graph can't be bipartite

int N, M, U, V;
vector<int> adj[mxN], colour(mxN);

bool checkCanBeColoured(int node) {
    for (int child: adj[node]) {
        if (colour[child] == -1) {
            colour[child] = 1 - colour[node];
            if(!checkCanBeColoured(child)){
                return false;
            }
        } else {
            if (colour[child] == colour[node]) {
                return false;
            }
        }
    }
    return true;
}