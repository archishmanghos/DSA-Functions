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

void checkViolation(Node *root, Node *&pre, tuple<Node *, Node *, Node *> &violation) {
    if (!root) {
        return;
    }

    checkViolation(root->left, pre, violation);
    if (pre and root->data < pre->data) {
        if (!get<0>(violation)) {
            get<0>(violation) = pre;
            get<1>(violation) = root;
        } else {
            get<2>(violation) = root;
        }
    }

    pre = root;
    checkViolation(root->right, pre, violation);
}

void recoverBST(Node *root) {
    Node *pre = NULL;
    tuple<Node *, Node *, Node *> violation = {NULL, NULL, NULL};
    checkViolation(root, pre, violation);

    if (!get<2>(violation)) {
        swap(get<0>(violation)->data, get<1>(violation)->data);
    } else {
        swap(get<0>(violation)->data, get<2>(violation)->data);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Node *root = buildTree();
    recoverBST(root);
    bfs(root);

    return 0;
}