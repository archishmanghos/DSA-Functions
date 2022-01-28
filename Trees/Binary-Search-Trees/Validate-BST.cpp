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

bool validBSTorNot(Node *root, int rangeMin, int rangeMax) {
    if (!root) {
        return true;
    }
    if (root->data > rangeMin and root->data < rangeMax) {
        return validBSTorNot(root->left, rangeMin, root->data) && validBSTorNot(root->right, root->data, rangeMax);
    }

    return false;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Node *root = buildTree();
    cout << validBSTorNot(root, -INF,INF);

    return 0;
}