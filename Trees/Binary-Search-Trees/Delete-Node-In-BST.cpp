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

Node *findParent(Node *root, Node *toFindNode) {
    Node *curNode = root;
    while (curNode) {
        if (curNode->left == toFindNode or curNode->right == toFindNode) {
            return root;
        }
        curNode = (toFindNode->data < curNode->data ? curNode->left : curNode->right);
    }
}

Node *findMaxNode(Node *root) {
    while (root->right or root->left) {
        root = (root->right ? root->right : root->left);
    }
    return root;
}

Node *deleteNodeInBST(Node *root, Node *deleteNode) {
    Node *curNode = searchNodeInBST(root, deleteNode);
    if (curNode) {
        if (curNode != root) {
            Node *parentNode = findParent(root, curNode);
            if (parentNode->left == curNode) {
                parentNode->left = curNode->left;
            } else {
                parentNode->right = curNode->left;
            }
            Node *maxNodeOnLeftSubtree = findMaxNode(curNode->left);
            maxNodeOnLeftSubtree->right = curNode->right;
            return root;
        } else {
            if (root->left) {
                Node *maxNodeOnLeftSubtree = findMaxNode(curNode->left);
                maxNodeOnLeftSubtree->right = curNode->right;
                root->right = NULL;
                root = root->left;
                return root;
            } else {
                return root->right;
            }
        }
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
    Node *deleteNode = new Node(12);
    root = deleteNodeInBST(root, deleteNode);
    bfs(root);

    return 0;
}