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

Node *inorderPredecessorinBST(Node *root, Node *givenNode) {
    Node *predecessor = NULL;
    while (root) {
        if (root->data < givenNode->data) {
            predecessor = root;
        }
        root = (root->data < givenNode->data ? root->right : root->left);
    }

    return predecessor;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Node *root = buildTree();
    Node *givenNode = new Node(5);
    Node *ans = inorderPredecessorinBST(root, givenNode);
    cout << (ans ? ans->data : -1);

    return 0;
}