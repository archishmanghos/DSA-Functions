// use a min heap of pairs, rest normally, take out the top element and compare the distance with the dist array and update for same

void distFromEachNode(int node) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, node});
    dist[node] = 0;

    while (!pq.empty()) {
        pair<int, int> curNode = pq.top();
        pq.pop();

        for (auto child: adj[curNode.second]) {
            if (curNode.first + child.second < dist[child.first]) {
                dist[child.first] = curNode.first + child.second;
                pq.push({dist[child.first], child.first});
            }
        }
    }
}