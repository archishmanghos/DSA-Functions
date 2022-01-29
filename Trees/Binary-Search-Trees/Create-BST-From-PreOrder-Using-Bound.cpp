#include <bits/stdc++.h>

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int value;

struct Node {
    int data;
    struct Node *left, *right;

    Node(int input) {
        data = input;
        left = right = NULL;
    }
};

Node *buildTree() {
    cin >> value;
    if (value == -1)
        return NULL;

    Node *root = new Node(value);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

void bfs(Node *root) {
    queue<Node *> q;
    q.push(root);

    while (!q.empty()) {
        int sz = q.size();
        for (int i = 1; i <= sz; i++) {
            Node *curNode = q.front();
            cout << curNode->data << ' ';
            q.pop();
            if (curNode->left != NULL)
                q.push(curNode->left);
            if (curNode->right != NULL)
                q.push(curNode->right);
        }
        cout << '\n';
    }
}

Node *createBSTfromPreOrderUsingBoundMethod(int upperBound, int &index, vector<int> &preOrder) {
    if (index >= preOrder.size() or preOrder[index] >= upperBound) {
        return NULL;
    }

    Node *newNode = new Node(preOrder[index]);
    index += 1;
    newNode->left = createBSTfromPreOrderUsingBoundMethod(newNode->data, index, preOrder);
    newNode->right = createBSTfromPreOrderUsingBoundMethod(upperBound, index, preOrder);

    return newNode;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int N;
    cin >> N;
    vector<int> preOrder(N);
    for (int i = 0; i < N; i++) {
        cin >> preOrder[i];
    }

    int index = 0;
    Node *root = createBSTfromPreOrderUsingBoundMethod(INF, index, preOrder);
    bfs(root);

    return 0;
}