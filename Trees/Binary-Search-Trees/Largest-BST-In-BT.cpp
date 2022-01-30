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

struct dimensions {
    int size, largest, smallest;
};

dimensions largestBSTinBT(Node *root) {
    if (!root) {
        dimensions d;
        d.size = 0, d.largest = -INF, d.smallest = INF;
        return d;
    }

    dimensions left = largestBSTinBT(root->left);
    dimensions right = largestBSTinBT(root->right);
    dimensions now;

    if (root->data > left.largest and root->data < right.smallest) {
        now.size = 1 + left.size + right.size;
        now.largest = max(right.largest, root->data);
        now.smallest = min(left.smallest, root->data);
    } else {
        now.size = max(left.size, right.size);
        now.largest = INF;
        now.smallest = -INF;
    }

    return now;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Node *root = buildTree();
    dimensions ans = largestBSTinBT(root);
    cout << ans.size;

    return 0;
}