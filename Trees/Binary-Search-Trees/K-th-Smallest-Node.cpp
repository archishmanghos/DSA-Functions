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

Node *kthSmallestNodeInBST(Node *root, int K)
{
    Node *curNode = root;
    int cnt = 0;
    while(curNode != NULL)
    {
        if(curNode->left == NULL)
        {
            cnt += 1;
            if(cnt == K)
                return curNode;
            curNode = curNode->right;
            continue;
        }

        Node *lastNodeonLeftSubTree = curNode->left;
        while(lastNodeonLeftSubTree->right and lastNodeonLeftSubTree->right != curNode)
                lastNodeonLeftSubTree = lastNodeonLeftSubTree->right;

        if(lastNodeonLeftSubTree->right == curNode)
        {
            cnt += 1;
            if(cnt == K)
                return curNode;
            lastNodeonLeftSubTree->right = NULL;
            curNode = curNode->right;
        }
        else
        {
            lastNodeonLeftSubTree->right = curNode;
            curNode = curNode->left;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = buildTree();
    cout << kthSmallestNodeInBST(root, 3)->data;

    return 0;
}