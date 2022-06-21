#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int value;

struct Node
{
    int data;
    struct Node *left, *right;
    Node(int input)
    {
        data = input;
        left = right = NULL;
    }
};

Node* buildTree()
{
    cin >> value;
    if(value == -1)
        return NULL;

    Node* root = new Node(value);
    root->left = buildTree();
    root->right = buildTree();
}

Node *lcaInBST(Node *root, pair<Node *, Node *> lca)
{
    while(root)
    {
        if(lca.first->data == root->data or lca.second->data == root->data)
            return root;
        if(lca.first->data < root->data and lca.second->data > root->data)
            return root;
        root = (lca.first->data < root->data ? root->left : root->right);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = buildTree();
    Node *lca1 = new Node(1);
    Node *lca2 = new Node(2);
    pair<Node *, Node *> lca = {lca1, lca2};
    cout << lcaInBST(root, lca)->data;

    return 0;
}